import sys
import time
import math
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.animation as animation


data = np.genfromtxt('Data.csv', delimiter=',',names=['x', 'y', 'z'],invalid_raise=False)

    #print data
fig = plt.figure(0)
ax1=Axes3D(fig)

    #fig2 = plt.figure(1)
    #ax2=Axes3D(fig2)
    #ax2.plot(data['x'],data['y'],0, color='r',label=Planets[1])
    #plt.show()
plt.title('Planets[1]')
xLabel = ax1.set_xlabel('X Au')
yLabel = ax1.set_ylabel('Y Au')
zLabel = ax1.set_zlabel('Z Au')

ax1.set_xlim(-1,1)
ax1.set_ylim(-1,1)
    #for i in range(len(data)):
        #animate(i)
ax1.hold(False)
n=1000
def animate(i):
        #print i
    plt.cla()
    ax1.grid(b=False)
    ax1.set_xticks([])
    ax1.set_yticks([])
    ax1.set_zticks([])



        #ax1.hold(False)
        #print i
        #for j in range(i*n,(i+1)*n):
    plt.hold(True)
    aX=data['x']
    aY=data['y']
    aZ=data['z']



        #print j
    ax1.plot(aX[i*n:(i+1)*n],aY[i*n:(i+1)*n],aZ[i*n:(i+1)*n],linestyle='none', marker='o', markersize=10,c='r')
            #plt.hold(False)
        #plt.hold(False)
ani = animation.FuncAnimation(fig, animate,10, interval=100,blit=False,repeat=True)

ax1.axis('off')
plt.show();
