import csv
import pandas as pd
import numpy as np

FILENAME = "D:\\Python\\IEEE\\waypoints.csv"

class Waypoint:
    def __init__(self,latitude,longitude,alt):
        self.latitude = latitude
        self.longitude = longitude
        self.alt = alt
    def get_long(self):
        return self.longitude
    def get_lat(self):
        return self.latitude
    def get_alt(self):
        return self.alt

waypoints = []
with open(FILENAME, newline = "") as file:
    reader = csv.reader(file)
    for row in reader:
        waypoint = Waypoint(row[0],row[1],row[2])
        waypoints.append(waypoint)

for waypoint in waypoints:
    latitude = waypoint.get_lat()
    longitude = waypoint.get_long()
    alt = waypoint.get_alt()
    print(str(latitude) + "," + str(longitude) + " : " + str(alt))

#you can store a csv file more efficently on pandas
df = pd.read_csv(FILENAME, index_col = 0) #Filename is a constant that contains the directory to a csv file
print(df)


