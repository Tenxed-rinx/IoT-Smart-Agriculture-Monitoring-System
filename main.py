import random
import pandas as pd
from datetime import datetime
import os

os.makedirs("data", exist_ok=True)

data_list = []

for i in range(10):

    soil = random.randint(200, 800)
    temp = random.randint(20, 45)
    humidity = random.randint(40, 90)
    light = random.randint(100, 1000)
    water = random.randint(100, 800)

    pump = "ON" if soil > 500 else "OFF"

    alert = []

    if soil > 500:
        alert.append("Dry Soil")

    if temp > 35:
        alert.append("High Temperature")

    if water < 200:
        alert.append("Low Water Level")

    timestamp = datetime.now()

    row = {
        "Timestamp": timestamp,
        "Soil": soil,
        "Temperature": temp,
        "Humidity": humidity,
        "Light": light,
        "Water": water,
        "Pump": pump,
        "Alerts": ", ".join(alert)
    }

    data_list.append(row)

df = pd.DataFrame(data_list)

df.to_csv("data/sensor_data.csv", index=False)

print(df)
print("\nData saved successfully!")