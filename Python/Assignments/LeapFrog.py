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

file=open('PlanetData.txt','r')



x,y,z,vx,vy,vz=(raw_input('>> Input x y Z, VX VY VZ corrdinates and velocity and angle').split())
x=np.float128(x)
y=np.float128(y)
z=np.float128(z)
vx=np.float128(vx)
vy=np.float128(vy)
vz=np.float128(vz)

#print x

N=1000
dt=1.0

t=0

#plt.ion()
#plt.show()

f=open('Data.csv','w')

while(t<365*20):


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

    f.write("%f,%f,%f\n" %(x,y,z))
f.close()
    #plt.plot(x,y,'or')
    #plt.draw()
    #time.sleep(0.005)

data = np.genfromtxt('Data.csv', delimiter=',',names=['x', 'y', 'z'])

#x=getColumn('Data.csv',1)
#y=getColumn('Data.csv',2)

#data= np.loadtxt('Data.csv',unpack=True,delimiter = ',',dtype=float)
#df = pd.read_csv('Data.csv',sep=',')
#data = np.array(df)

fig = plt.figure()
ax=Axes3D(fig)


#print data
#plt.plot(data['x'],data['y'], color='r', label='the data')
#plt.plot(data['x'], data['y'], color='r', label='the data')
ax.plot(data['x'],data['y'],data['z'], color='r', label='the data')

plt.show(block=True)
