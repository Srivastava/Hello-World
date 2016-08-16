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


    #for i in range(len(data)):
        #animate(i)
#ax1.hold(False)
fig = plt.figure(0)

n=1000
def animate(i):


    #ax1.axis3don=False
    #ax1.set_axis_off()
    ax1=Axes3D(fig)
    ax1.set_xticks([])
    ax1.set_yticks([])

    ax1.set_zticks([])



        #fig2 = plt.figure(1)
        #ax2=Axes3D(fig2)
        #ax2.plot(data['x'],data['y'],0, color='r',label=Planets[1])
        #plt.show()
    plt.title('Plummer Sphere')
    xLabel = ax1.set_xlabel('X Au')
    yLabel = ax1.set_ylabel('Y Au')
    zLabel = ax1.set_zlabel('Z Au')

        #print i
    #plt.figure(0)
    #plt.clf()

    #fig.gca().cla()
    ax1.set_xlim(-2,2)
    ax1.set_ylim(-2,2)
    ax1.set_zlim(-2,2)
    ax1.grid(b=False)
    ax1.axis('off')
    #ax1.set_xticks([])
    #ax1.set_yticks([])

    #ax1.set_zticks([])



        #ax1.hold(False)
        #print i
        #for j in range(i*n,(i+1)*n):

    #ax1.set_axis_off()




    #ax1.axes.get_xaxis().set_visible(False)
    #ax1.axes.get_yaxis().set_visible(False)


    aX=data['x']
    aY=data['y']
    aZ=data['z']



    #ax1.hold(True)    #print j
    ax1.plot(aX[i*n:(i+1)*n],aY[i*n:(i+1)*n],aZ[i*n:(i+1)*n],linestyle='none', marker='o', markersize=2,c='r')
    #ax1.hold(False)


    #plt.clf()
        #plt.hold(False)
ani = animation.FuncAnimation(fig, animate,1000, interval=200,blit=False,repeat=True)


plt.show();
