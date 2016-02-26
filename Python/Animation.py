import sys
import time
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.animation as animation

GM =0.00029632889

def accel(x,y,z,val):
    dist=(x*x+y*y+z*z)**(-1.5)
    return -GM*val*dist

Planets=['All Planets','Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus','Neptune','Pluto']

n=1
for line in sys.stdin.readlines():
    fs = [float(f) for f in line.split(",")]

    x,y,z,vx,vy,vz,Year=fs
    x=np.float128(x)
    y=np.float128(y)
    z=np.float128(z)
    vx=np.float128(vx)
    vy=np.float128(vy)
    vz=np.float128(vz)
    Year=np.float128(Year)

    N=60000
    dt=1.0

    t=0

    values=[]
    while(t<Year*365):

        ax=accel(x,y,z,x)
        ay=accel(x,y,z,y)
        az=accel(x,y,z,z)

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

    with open(Planets[n]+'.csv', 'wb') as filePointer:
        a = csv.writer(filePointer)
        a.writerows(values)
    n+=1

allfig = plt.figure(0)
ax1=Axes3D(allfig)
line,=ax1.plot([],[],[])

m=0
data = np.genfromtxt('Mercury.csv', delimiter=',',names=['x', 'y', 'z'],invalid_raise=False)

def animate(i):
    global m
    print i

    line.set_data(data[m][0],data[m][1])
    line.set_3d_properties(data[m][2])
    m+=1
    allfig.canvas.draw()
    return line

ani = animation.FuncAnimation(allfig, animate, frames=10,blit=False)
plt.show()
