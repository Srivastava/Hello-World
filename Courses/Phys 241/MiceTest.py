import sys
import time
import math
import scipy as sp
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.animation as animation

GM =0.00029632889 * 10E11
#GM = 4.498309551e-8
#GM =1E-3
GMm =10E-12
GMS=8.46611639e-8
print GM


def accel(x,y,z,n):
    ax=sp.zeros([n])
    ay=sp.zeros([n])
    az=sp.zeros([n])

    #dist11=((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])+(z[1]-z[0])*(z[1]-z[0]))**(-1.5)
    #print dist11, x[1], x[0], y[1], y[0], z[1], z[0]

    dist11=((x[0]*x[0]+y[0]*y[0]+z[0]*z[0]))*(-1.5)
    aX11=-2*GM*(x[0])*dist11
    aY11=-2*GM*(y[0])*dist11
    aZ11=-2*GM*(z[0])*dist11

    ax[0]=aX11
    ay[0]=aY11
    az[0]=aZ11

    dist11=((x[1]*x[1]+y[1]*y[1]+z[1]*z[1]))*(-1.5)
    aX11=-2*GM*(x[1])*dist11
    aY11=-2*GM*(y[1])*dist11
    aZ11=-2*GM*(z[1])*dist11


    ax[1]=aX11
    ay[1]=aY11
    az[1]=aZ11

    for i in range (2,n):
        aX=0
        aY=0
        aZ=0


        dist=((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0])+(z[i]-z[0])*(z[i]-z[0]))**(-1.5)
        dist1=((x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1])+(z[i]-z[1])*(z[i]-z[1]))**(-1.5)

        aX=-GM*(x[i]-x[0])*dist
        aY=-GM*(y[i]-y[0])*dist
        aZ=-GM*(z[i]-z[0])*dist

        aX1=-GM*(x[i]-x[1])*dist1
        aY1=-GM*(y[i]-y[1])*dist1
        aZ1=-GM*(z[i]-z[1])*dist1

        ax[i]=aX+aX1
        ay[i]=aY+aY1
        az[i]=aZ+aZ1


    return (ax,ay,az)


def LeapState(x,y,z,vx,vy,vz,n):

    dt =0.00001

    ax,ay,az=accel(x,y,z,n)

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


def init(npart):
    x=[]
    y=[]
    z=[]
    vx=[]
    vy=[]
    vz=[]

    Rmin=5.0
    e=0.6
    a=float(Rmin/(2*(1-e)))
    Ra=a*(1+e)

    VelMass=GM*((1+e)/(a-a*e))
    VelMass=VelMass**0.5

    vel=2*GM/Ra
    vel=vel**0.5
    vx.append(0)
    vy.append(vel)
    vz.append(0)

    vx.append(0)
    vy.append(-vel)
    vz.append(0)

    x.append(-Ra)
    y.append(0)
    z.append(0)

    x.append(Ra)
    y.append(0)
    z.append(0)

    for i in range(0,11):
        r=(0.2+0.05*i)*Rmin
        velocity=(GM/r)
        velocity=velocity**(0.5)
        n=12+3*i
        for j in range(0,n):
            x.append(r*np.cos((2*np.pi*j)/n)-Ra)
            y.append(r*np.sin((2*np.pi*j)/n))
            z.append(0.0)

            vx.append(-velocity*np.sin((2*np.pi*j)/n))
            vy.append(velocity*np.cos((2*np.pi*j)/n))
            vz.append(0.0)

    for i in range(0,11):
        #print i
        r=(0.2+0.05*i)*Rmin
        #print 0.2+0.05*i
        velocity=(GM/r)
        velocity=velocity**(0.5)

        n=12+3*i
        #print n
        for j in range(0,n):
            x.append(r*np.cos((2*np.pi*j)/n)+Ra)
            y.append(r*np.sin((2*np.pi*j)/n))
            z.append(0.0)

            vx.append(-velocity*np.sin((2*np.pi*j)/n))
            vy.append(velocity*np.cos((2*np.pi*j)/n))
            vz.append(0.0)

    return (x,y,z,vx,vy,vz)

def main():
    #n,t=(raw_input('>> N, T ').split())
    t=(raw_input('>>T ').split())
    #n=np.int64(n)
    n=596
    t=np.float128(t)

    x,y,z,vx,vy,vz=init(n)

    N=np.int64(math.ceil(t/1))


    f=open('DataT.csv','w')
    with open('DataT.csv', 'wb') as fp:
        a = csv.writer(fp)

        for i in range(0,N):
            for j in range(0,n):
                values=[]
                values.append([x[j],y[j],z[j]])
                a.writerows(values)

            x,y,z,vx,vy,vz=LeapState(x,y,z,vx,vy,vz,n)



    f.close()
main()
