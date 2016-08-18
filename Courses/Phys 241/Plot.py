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


n,t=(raw_input('>>N,T ')).split()

dt=1E+7
n=np.int64(n)
t=np.int64(t)

fig=plt.figure()

ax1 = fig.add_subplot(111, projection='3d')


#ax1=Axes3D(fig)
#text=plt.text(0.1,1,1,"Pure Advection at t=0",ha='center',va='top',transform = ax.transAxes,fontsize='18')
def animate(i):

    #ax1.set_xticks([])
    #ax1.set_yticks([])

    #ax1.set_zticks([])

    plt.cla()

    text=ax1.text(0, 0, 40, "red", color='red')
    plt.title('Toomre Galaxy Collision')
    xLabel = ax1.set_xlabel('X KPa')
    yLabel = ax1.set_ylabel('Y KPa')
    zLabel = ax1.set_zlabel('Z KPa')

    ax1.set_xlim(-30,30)
    ax1.set_ylim(-30,30)
    ax1.set_zlim(-30,30)
    ax1.grid(b=True)
    #ax1.axis('off')




    aX=data['x']
    aY=data['y']
    aZ=data['z']

    ax1.hold(True)
    ax1.plot(aX[i*n:i*n+2],aY[i*n:i*n+2],aZ[i*n:i*n+2],linestyle='none', marker='o', markersize=10,c='b')
    ax1.plot(aX[i*n+2:(i+1)*n],aY[i*n+2:(i+1)*n],aZ[i*n+2:(i+1)*n],linestyle='none', marker='o', markersize=2,c='r')
    text.set_text("t=: {0}years".format(dt*(i+1)))
    ax1.hold(False)


ani = animation.FuncAnimation(fig, animate,t, interval=100,blit=False,repeat=False)
writer = animation.writers['avconv'](fps=30)
ani.save('demo.mp4',writer=writer,dpi=360)
'''with writer.saving(fig, "writer_test.mp4", 100):
    for i in range(t):
        plt.cla()

        text=ax1.text(0, 0, 40, "red", color='red')
        plt.title('Toomre Galaxy Collision')
        xLabel = ax1.set_xlabel('X KPa')
        yLabel = ax1.set_ylabel('Y KPa')
        zLabel = ax1.set_zlabel('Z KPa')

        ax1.set_xlim(-30,30)
        ax1.set_ylim(-30,30)
        ax1.set_zlim(-30,30)
        ax1.grid(b=True)
        #ax1.axis('off')




        aX=data['x']
        aY=data['y']
        aZ=data['z']

        ax1.hold(True)
        ax1.plot(aX[i*n:i*n+2],aY[i*n:i*n+2],aZ[i*n:i*n+2],linestyle='none', marker='o', markersize=10,c='b')
        ax1.plot(aX[i*n+2:(i+1)*n],aY[i*n+2:(i+1)*n],aZ[i*n+2:(i+1)*n],linestyle='none', marker='o', markersize=2,c='r')
        text.set_text("t=: {0}years".format(dt*(i+1)))
        ax1.hold(False)

        writer.grab_frame()'''



plt.show();
