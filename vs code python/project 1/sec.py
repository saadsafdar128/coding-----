import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score


df=pd.read_csv('chemistry_elements_dataset.csv ')

x=df[['Atomic_Number','Group','Category']]
y=df['State_At_Room_Temperature']


x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=100)
model=RandomForestClassifier(random_state=100)
model.fit(x_train,y_train)

prediction=model.predict(x_test)

accuracy=accuracy_score(y_test,prediction)
print(f"accuracy: {accuracy*100}")




