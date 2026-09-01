from dotenv import load_dotenv
from pydantic import BaseModel
from langchain_openai import ChatOpenAI
from langchain_anthropic import ChatAnthropic

load_dotenv()

llm=ChatOpenAI(model="gpt-5.6-luna")
read=llm.invoke("tell me about the sea substacnes")
print(read)
