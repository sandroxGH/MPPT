#https://plotly.com/python/plot-data-from-csv/

import plotly.graph_objects as go
from plotly.subplots import make_subplots
import pandas as pd
import plotly.express as px
from datetime import datetime
import time

df = pd.read_csv ('~/Desktop/MPPT Prj/grafico/' + input('Enter file name  '))

#df = pd.read_csv ('~/Desktop/MPPT Prj/grafico/200715')

Start_Time = input('Enter start time record ')
#Start_Time = "9:00"
if(Start_Time[1]==":"):
    Start_Time = "0"+Start_Time
if(Start_Time[2]==":"):
    Start_Time =Start_Time +":00"

Stop_Time = input('Enter stop time record ')
#Stop_Time = "10:00"
if(Stop_Time[1]==":"):
    Stop_Time = "0"+Stop_Time
if(Stop_Time[2]==":"):
    Stop_Time =Stop_Time +":00"
 
print(Start_Time)
print(Stop_Time)    
    
#Time1 = datetime.strptime(Start_Time, '%H:%M:%S')
#Time2 = datetime.strptime(Stop_Time, '%H:%M:%S')

if((Start_Time[2]==":")| (Stop_Time[2]==":")):
    df = df.iloc[df.index[(df['time']>Start_Time) & (df['time']<Stop_Time)].tolist()]   

#print(df)


fig = make_subplots(rows=6,cols=1)#, shared_xaxes=True

# specs=[[{"secondary_y": True}, {"secondary_y": True}, {"secondary_y": True}, {"secondary_y": True}]])


fig.add_trace(
	#go.Scatter(  x = df['time'],y = df['VIn'], name="VIn"),
    go.Scatter( y = df['VIn'], name="VIn"),
    row=1,col=1
)


fig.add_trace(
    go.Scatter( x = df['time'],y = df['AIn'], name="AIn"),
    row=2,col=1, 
)


fig.add_trace(
    go.Scatter(x = df['time'], y = df['PWM'], name="PWM"),
    row=3,col=1
)

fig.add_trace(
    go.Scatter( x = df['time'],y = df['VOut'], name="VOut"),
    row=4,col=1
)
fig.add_trace(
    go.Scatter(x = df['time'], y = df['POut'], name="POut"),
    row=5,col=1
)
fig.add_trace(
    go.Scatter(x = df['time'], y = df['EnProd'], name="EnProd"),
    row=6,col=1
)
fig.update_layout(height=1600,title_text="MPPT")
#fig.update_layout(height=600, width=800, title_text="Side By Side Subplots")
fig.show()
