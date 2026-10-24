import streamlit as st
import pandas as pd
import os

st.title("🌱 Smart Agriculture Dashboard")

# Get current file location
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# Create correct CSV path
csv_path = os.path.join(BASE_DIR, "..", "data", "sensor_data.csv")

# Check if file exists
if os.path.exists(csv_path):

    df = pd.read_csv(csv_path)

    st.subheader("Sensor Data")
    st.dataframe(df)

    st.subheader("Temperature")
    st.line_chart(df["Temperature"])

    st.subheader("Soil Moisture")
    st.line_chart(df["Soil"])

    st.subheader("Humidity")
    st.line_chart(df["Humidity"])

else:
    st.error("sensor_data.csv not found!")
    st.info("Run main.py first to generate sensor data.")