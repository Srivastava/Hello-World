import sys
import time
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D

GM =0.00029632889
print GM


def accel(x,y,z,val):
    dist=(x*x+y*y+z*z)**(-1.5)
    #dist=np.power(dist,1.5)
    #print dist
    return -GM*val*dist




Planets=['All Planets','Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus','Neptune','Pluto']

allfig = plt.figure(0)
ax1=Axes3D(allfig)
n=1
for line in sys.stdin.readlines():
    fs = [float(f) for f in line.split(",")]
    #print fs


#file=open('PlanetData.txt','r')
#x,y,z,vx,vy,vz=(raw_input('>> Input x y Z, VX VY VZ corrdinates and velocity and angle').split())
    x,y,z,vx,vy,vz,Year=fs
    x=np.float128(x)
    y=np.float128(y)
    z=np.float128(z)
    vx=np.float128(vx)
    vy=np.float128(vy)
    vz=np.float128(vz)
    Year=np.float128(Year)

#print x

    N=60000
    dt=1.0

    t=0

#plt.ion()
#plt.show()

    #f=open('Data.csv','w')
    #with open('Data.csv', 'wb') as fp:
        #a = csv.writer(fp)
    #data = [['Me', 'You'],
            #['293', '219'],
            #['54', '13']]
    values=[]
    while(t<Year*365):


        ax=accel(x,y,z,x)
        ay=accel(x,y,z,y)
        az=accel(x,y,z,z)
    #print ax
    #print(x_0,y_0,vx_0,vy_0,t)
        vx+=0.5*dt*ax
        vy+=0.5*dt*ay
        vz+=0.5*dt*az

        x+=dt*vx
        y+=dt*vy
        z+=dt*vz

        ax=accel(x,y,z,x)
        ay=accel(x,y,z,y)
        az=accel(x,y,z,z)

        vx+=0.5*dt*ax
        vy+=0.5*dt*ay
        vz+=0.5*dt*az

        t+=1
        values.append([x,y,z])
            #f.write("%f,%f,%f\n" %(x,y,z))
            #data=[x,y,z]
            #a.writerows([x, y, z])
        #f.close()
    #plt.plot(x,y,'or')
    #plt.draw()
    #time.sleep(0.005)
    with open('Data.csv', 'wb') as fp:
        a = csv.writer(fp)
        a.writerows(values)
    data = np.genfromtxt('Data.csv', delimiter=',',names=['x', 'y', 'z'],invalid_raise=False)

#x=getColumn('Data.csv',1)
#y=getColumn('Data.csv',2)

#data= np.loadtxt('Data.csv',unpack=True,delimiter = ',',dtype=float)
#df = pd.read_csv('Data.csv',sep=',')
#data = np.array(df)

    fig = plt.figure(n)
    ax=Axes3D(fig)
    ax.plot(data['x'],data['y'],data['z'], color='r',label=Planets[n])
    plt.title(Planets[n])
    xLabel = ax.set_xlabel('X Au')
    yLabel = ax.set_ylabel('Y Au')
    zLabel = ax.set_zlabel('Z Au')
    fig.savefig(Planets[n]+'.png',bbox_inches='tight')
    handles, labels = ax.get_legend_handles_labels()


    ax.legend(handles[::-1], labels[::-1])



    ax1.plot(data['x'],data['y'],data['z'], c=np.random.rand(3,1),label=Planets[n])
    allfig.hold(True)
    n+=1
#print data
#plt.plot(data['x'],data['y'], color='r', label='the data')
#plt.plot(data['x'], data['y'], color='r', label='the data')

#f.close()
#plt.hold(True)
#allfig.legend(loc='upper left')
handles, labels = ax1.get_legend_handles_labels()
ax1.legend(handles[::-1], labels[::-1])
allfig.savefig(Planets[0]+'.png',bbox_inches='tight')
plt.show(block=True)
