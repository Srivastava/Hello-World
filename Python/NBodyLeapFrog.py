import sys
import time
import math
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.backends.backend_pdf import PdfPages

GM =0.00029632889
print GM


def accel(x,y,z,n):
    ax=[]
    ay=[]
    az=[]

    for i in range (0,n):
        dist=(x[i]*x[i]+y[i]*y[i]+z[i]*z[i])**(-1.5)

        ax.append(-GM*x[i]*dist)
        ay.append(-GM*y[i]*dist)
        az.append(-GM*z[i]*dist)

    return (ax,ay,az)


def LeapState(x,y,z,vx,vy,vz,n):

    dt =1

    ax,ay,az=accel(x,y,z,n)


    #print ax[0], ay[0], az[0]
    vx=[a+b*0.5*dt for a,b in zip(vx,ax)]
    vy=[a+b*0.5*dt for a,b in zip(vy,ay)]
    vz=[a+b*0.5*dt for a,b in zip(vz,az)]

    x=[a+b*dt for a,b in zip(x,vx)]
    y=[a+b*dt for a,b in zip(y,vy)]
    z=[a+b*dt for a,b in zip(z,vz)]

    ax,ay,az=accel(x,y,z,n)

    vx=[a+b*0.5*dt for a,b in zip(vx,ax)]
    vy=[a+b*0.5*dt for a,b in zip(vy,ay)]
    vz=[a+b*0.5*dt for a,b in zip(vz,az)]

    return (x,y,z,vx,vy,vz)

def init(n):
    x=[]
    y=[]
    z=[]
    vx=[]
    vy=[]
    vz=[]


    for i in range(0,n):
        x.append(-3.283291970503574E-01)
        y.append(1.319124272665584E-01)
        z.append(4.095649105518744E-02)

        vx.append(-1.608369028928803E-02)
        vy.append(-2.498400337798165E-02)
        vz.append(-5.664021783703915E-04)

    print x[0],y[0],z[0]
    return (x,y,z,vx,vy,vz)


Planets=['All Planets','Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus','Neptune','Pluto']
def main():
    n,t=(raw_input('>> N, T').split())
    n=np.int64(n)
    t=np.float128(t)

    x,y,z,vx,vy,vz=init(n)

    N=np.int64(math.ceil(t/1))


    f=open('Data.csv','w')
    with open('Data.csv', 'wb') as fp:
        a = csv.writer(fp)

        for i in range(0,N):
            for j in range(0,n):
                values=[]
                values.append([x[j],y[j],z[j]])
                a.writerows(values)

            x,y,z,vx,vy,vz=LeapState(x,y,z,vx,vy,vz,n)



    f.close()

    data = np.genfromtxt('Data.csv', delimiter=',',names=['x', 'y', 'z'],invalid_raise=False)

    fig = plt.figure(0)
    ax=Axes3D(fig)
    ax.plot(data['x'],data['y'],data['z'], color='r',label=Planets[1])
    plt.title(Planets[1])
    xLabel = ax.set_xlabel('X Au')
    yLabel = ax.set_ylabel('Y Au')
    zLabel = ax.set_zlabel('Z Au')
    fig.savefig(Planets[1]+'.png',bbox_inches='tight')

    plt.show();
main()

#plt.show(block=True)
