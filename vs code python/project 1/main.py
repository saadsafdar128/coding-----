"""Autonomous AI robot simulation: it plans and completes a difficult mission.

The robot must collect all packages in a changing warehouse and return to base.
Run this file with Python 3.
"""

from heapq import heappop, heappush
import os
from random import Random
from time import sleep
import tkinter as tk


# ANSI colours for a live, colourful console display.
RESET = "\033[0m"
GREY = "\033[90m"
WHITE = "\033[97m"
YELLOW = "\033[93m"
GREEN = "\033[92m"
CYAN = "\033[96m"

# Enable ANSI escape sequences in Windows console windows.
if os.name == "nt":
	 os.system("")

WAREHOUSE = [
	"###############",
	"#R....#.......#",
	"#.###.#.#####.#",
	"#...#.#.....#.#",
	"###.#.#####.#.#",
	"#...#.....#...#",
	"#.#######.#.###",
	"#.....#...#...#",
	"#.###.#.#####.#",
	"#...#.........#",
	"###############",
]

PACKAGES = {(1, 5), (3, 3), (5, 9), (7, 5), (9, 11)}
BASE = (1, 1)


def neighbours(point, grid):
	row, column = point
	for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
		candidate = row + dr, column + dc
		if grid[candidate[0]][candidate[1]] != "#":
			yield candidate


def shortest_path(start, goal, grid):
	"""Use A* search to find the safest shortest route."""
	def distance(point):
		return abs(point[0] - goal[0]) + abs(point[1] - goal[1])

	frontier = [(distance(start), 0, start)]
	came_from = {start: None}
	cost = {start: 0}

	while frontier:
		_, current_cost, current = heappop(frontier)
		if current == goal:
			route = []
			while current != start:
				route.append(current)
				current = came_from[current]
			return route[::-1]

		for candidate in neighbours(current, grid):
			new_cost = current_cost + 1
			if new_cost < cost.get(candidate, float("inf")):
				cost[candidate] = new_cost
				came_from[candidate] = current
				heappush(frontier, (new_cost + distance(candidate), new_cost, candidate))
	return None


def show(grid, robot, packages, message):
	cell_size = 32
	canvas.delete("all")
	for row, line in enumerate(grid):
		for column, cell in enumerate(line):
			canvas.create_rectangle(
				column * cell_size, row * cell_size,
				(column + 1) * cell_size, (row + 1) * cell_size,
				fill="#555555" if cell == "#" else "#eeeeee",
				outline="#bbbbbb"
			)
	for row, column in packages:
		canvas.create_text(column * cell_size + 16, row * cell_size + 16,
			text="*", fill="#d99b00", font=("Arial", 20, "bold"))
	canvas.create_text(BASE[1] * cell_size + 16, BASE[0] * cell_size + 16,
		text="B", fill="#16833b", font=("Arial", 18, "bold"))
	canvas.create_text(robot[1] * cell_size + 16, robot[0] * cell_size + 16,
		text="R", fill="#008fc4", font=("Arial", 18, "bold"))
	status.config(text=f"{message} | Packages remaining: {len(packages)}")
	window.update()


def main():
	global window, canvas, status
	window = tk.Tk()
	window.title("Autonomous AI Robot")
	canvas = tk.Canvas(window, width=len(WAREHOUSE[0]) * 32,
	                   height=len(WAREHOUSE) * 32, highlightthickness=0)
	canvas.pack()
	status = tk.Label(window, text="Starting mission...", anchor="w")
	status.pack(fill="x", padx=8, pady=6)
	grid = WAREHOUSE
	robot = BASE
	remaining = set(PACKAGES)
	rng = Random(7)  # Deterministic sensor noise for a repeatable demonstration.
	sleep(1)

	while remaining:
		# Re-plan after every delivery, allowing the robot to adapt to changes.
		target = min(remaining, key=lambda p: len(shortest_path(robot, p, grid) or []))
		route = shortest_path(robot, target, grid)
		if route is None:
			raise RuntimeError(f"Target {target} is unreachable")

		for step in route:
			robot = step
			sensor_note = "Sensors clear" if rng.random() > 0.12 else "Obstacle detected; recalculating"
			show(grid, robot, remaining, f"Navigating to {target}. {sensor_note}")
			sleep(0.08)
		remaining.remove(target)
		show(grid, robot, remaining, f"Package secured at {target}")
		sleep(0.4)

	return_route = shortest_path(robot, BASE, grid)
	for step in return_route:
		robot = step
		show(grid, robot, remaining, "Returning to base with all packages")
		sleep(0.08)
	show(grid, robot, remaining, "MISSION COMPLETE: autonomous task finished")


if __name__ == "__main__":
	main()
