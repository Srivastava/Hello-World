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
fig = plt.figure(0)

n,t=(raw_input('>>N,T ')).split()

n=np.int64(n)
t=np.int64(t)
ax1=Axes3D(fig)
def animate(i):

    #ax1.set_xticks([])
    #ax1.set_yticks([])

    #ax1.set_zticks([])
    plt.cla()

    plt.title('Planets[1]')
    xLabel = ax1.set_xlabel('X Au')
    yLabel = ax1.set_ylabel('Y Au')
    zLabel = ax1.set_zlabel('Z Au')

    ax1.set_xlim(-30,30)
    ax1.set_ylim(-30,30)
    ax1.set_zlim(-30,30)
    ax1.grid(b=True)
    ax1.axis('off')




    aX=data['x']
    aY=data['y']
    aZ=data['z']

    ax1.hold(True)
    ax1.plot(aX[i*n:i*n+2],aY[i*n:i*n+2],aZ[i*n:i*n+2],linestyle='none', marker='o', markersize=10,c='b')
    ax1.plot(aX[i*n+2:(i+1)*n],aY[i*n+2:(i+1)*n],aZ[i*n+2:(i+1)*n],linestyle='none', marker='o', markersize=2,c='r')

ani = animation.FuncAnimation(fig, animate,t, interval=100,blit=False,repeat=False)


plt.show();
