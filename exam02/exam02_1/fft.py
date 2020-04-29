import matplotlib.pyplot as plt

import numpy as np

import serial

import time

t = np.arange(0,100,1)


total = np.arange(-1,1,0.02)
five_cm = np.arange(0,1,0.01)

serdev = '/dev/ttyACM0'

s = serial.Serial(serdev,115200)

for i in range(1,100):

    line_total=s.readline() # Read an echo string from K66F terminated with '\n'
    total[i] = float(line_total)
    
    line_five=s.readline()
    five_cm[i] = float(line_five)


fig, ax = plt.subplots(2, 1)

ax[0].plot(t,total,label='total')

ax[0].set_xlabel('Time')

ax[0].set_ylabel('X_displacement')

ax[1].stem(t,five_cm,use_line_collection = True) 

ax[1].set_xlabel('Time')

ax[1].set_ylabel('whether displacement larger than 5cm')

plt.show()