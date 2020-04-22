import matplotlib.pyplot as plt

import numpy as np

import serial

import time

t = np.arange(0,100,1)


x = np.arange(-1,1,0.02)
y = np.arange(-1,1,0.02)
z = np.arange(-1,1,0.02)
tilt = np.arange(0,1,0.01)

serdev = '/dev/ttyACM0'

s = serial.Serial(serdev,115200)

for i in range(1,100):

    line_x=s.readline() # Read an echo string from K66F terminated with '\n'
    x[i] = float(line_x)

    line_y=s.readline()
    y[i] = float(line_y)
    
    line_z=s.readline()
    z[i] = float(line_z)
    
    line_tilt=s.readline()
    tilt[i] = float(line_tilt)


fig, ax = plt.subplots(2, 1)

ax[0].plot(t,x,label='x')

ax[0].plot(t,y,label='y')

ax[0].plot(t,z,label='z')

ax[0].set_xlabel('Time')

ax[0].set_ylabel('ACC_vector')

ax[1].stem(t,tilt,use_line_collection = True) 

ax[1].set_xlabel('Time')

ax[1].set_ylabel('whether_tilt')

plt.show()