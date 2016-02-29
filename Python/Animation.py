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

allfig = plt.figure(facecolor='black')
plt.gca().patch.set_facecolor('black')
ax1=Axes3D(allfig)
#line,=ax1.plot([],[],[])

m=0
data = np.genfromtxt('Mercury.csv', delimiter=',', names=['x', 'y', 'z'])
#for dat in data:
    #print dat

#line=
#line=ax1.plot(data['x'], data['y'], data['z'])
#
#allfig.axes('off')

ax1.axes.get_yaxis().set_visible(False)
ax1.axes.get_xaxis().set_visible(False)
#ax1.axes.get_zaxis().set_visible(False)

#ax1.set_axis_off()

ax1.hold(False)
def animate(i):

    #print i
    ax1.plot([data[i][0]],[data[i][1]],[data[i][2]],linestyle='none', marker='o', markersize=50,color='r')

#for i in range(len(data)):
    #animate(i)

ani = animation.FuncAnimation(allfig, animate,86, interval=86,blit=False)
plt.show()
