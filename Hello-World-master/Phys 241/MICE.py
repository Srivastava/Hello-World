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

#GM =0.00029632889 * 10E11
GM = 4.498309551e-13
#GM=4.43E-6
#GM =1E-3
#GMm =10E-12
#GMS=8.46611639e-8
#print GM


def rotation (x,y,z,nx,ny,nz,angle):
    theta=-np.pi*angle/180.0


    c=np.cos(theta)
    s=np.sin(theta)
    a=1-c

    xN=[0]*len(x)
    yN=[0]*len(x)
    zN=[0]*len(x)

    #print a*nx*nx+c ,a*nx*ny-s*nz,a*nx*nz+s*ny
    #print a*nx*ny+s*nz,a*ny*ny+c,a*ny*nz-s*nx
    #print a*nx*nz-s*ny, a*ny*nz+s*nx, a*nz*nz+c

    xN=[(a*nx*nx+c)*p+(a*nx*ny-s*nz)*q+(a*nx*nz+s*ny)*r for p,q,r in zip(x,y,z)]
    yN=[(a*nx*ny+s*nz)*p+(a*ny*ny+c)*q+(a*ny*nz-s*nx)*r for p,q,r in zip(x,y,z)]
    zN=[(a*nx*nz-s*ny)*p+(a*ny*nz+s*nx)*q+(a*nz*nz+c)*r for p,q,r in zip(x,y,z)]



    '''print len(xN)
    print len(yN)
    print len(zN)'''

    return (xN,yN,zN)

def accel(x,y,z,n):
    ax=sp.zeros([n])
    ay=sp.zeros([n])
    az=sp.zeros([n])

    '''dist11=((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])+(z[1]-z[0])*(z[1]-z[0]))**(-1.5)
    #print dist11, x[1], x[0], y[1], y[0], z[1], z[0]

    aX11=-GM*(x[1]-x[0])*dist11
    aY11=-GM*(y[1]-y[0])*dist11
    aZ11=-GM*(z[1]-z[0])*dist11

    ax[0]=-aX11
    ay[0]=-aY11
    az[0]=-aZ11

    ax[1]=aX11
    ay[1]=aY11
    az[1]=aZ11'''

    dist11=((x[0]*x[0]+y[0]*y[0]+z[0]*z[0])+10E-6)**(-1.5)
    aX11=-GM*(x[0])*dist11*0.5
    aY11=-GM*(y[0])*dist11*0.5
    aZ11=-GM*(z[0])*dist11*0.5

    ax[0]=aX11
    ay[0]=aY11
    az[0]=aZ11

    dist12=((x[1]*x[1]+y[1]*y[1]+z[1]*z[1])+10E-6)**(-1.5)
    aX12=-GM*(x[1])*dist12*0.5
    aY12=-GM*(y[1])*dist12*0.5
    aZ12=-GM*(z[1])*dist12*0.5

    ax[1]=aX12
    ay[1]=aY12
    az[1]=aZ12

    for i in range (2,n):
        aX=0
        aY=0
        aZ=0


        dist=((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0])+(z[i]-z[0])*(z[i]-z[0])+10E-6)**(-1.5)
        dist1=((x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1])+(z[i]-z[1])*(z[i]-z[1])+10E-6)**(-1.5)

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

    dt =1E+7

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

    Rmin=25.0
    e=0.6
    a=float(Rmin/(2*(1-e)))
    print a
    Ra=a*(1+e)
    #Ra=Rmin*(1+e)*((1-e)**(-1))
    #print a,Ra
    #VelMass=GM*((1+e)/(a-a*e))
    #VelMass=VelMass**0.5

    #vel=(GM*((2.0/Ra) - (1.0/a)))**0.5
    vel = (GM*0.5*Rmin*((Ra*(Ra+Rmin))**(-1)))**(0.5)
    #vel =0.5*(GM*(1-e)*(1-e)*((3+e)*Rmin)**(-1))**(0.5)

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
        velocity=((GM/r))**0.5

        n=12+3*i
        for j in range(0,n):
            x.append(r*np.cos((2*np.pi*j)/n))
            y.append(r*np.sin((2*np.pi*j)/n))
            z.append(0.0)

            vx.append(-velocity*np.sin((2*np.pi*j)/n))
            vy.append(velocity*np.cos((2*np.pi*j)/n))
            vz.append(0.0)

    x[2:],y[2:],z[2:]=rotation(x[2:],y[2:],z[2:],1.0,0.0,0.0,60.0)

    vx[2:],vy[2:],vz[2:]=rotation(vx[2:],vy[2:],vz[2:],1.0,0.0,0.0,60.0)
    #vx[0],vy[0],vz[0]=rotation([vx[0]],[vy[0]],[vz[0]],0.0,1.0,0.0,60.0)


    #x[2:],y[2:],z[2:]=rotation(x[2:],y[2:],z[2:],1.0,0.0,0.0,90.0)
    #vx[2:],vy[2:],vz[2:]=rotation(vx[2:],vy[2:],vz[2:],1.0,0.0,0.0,90.0)



    x[2:]=[p-Ra for p in x[2:]]
    vy[2:]=[p+vel for p in vy[2:]]


    for i in range(0,11):
        #print i
        r=(0.2+0.05*i)*Rmin
        #print 0.2+0.05*i
        velocity=((GM/r))**0.5
        n=12+3*i
        #print n
        for j in range(0,n):
            x.append(r*np.cos((2*np.pi*j)/n))
            y.append(r*np.sin((2*np.pi*j)/n))
            z.append(0.0)

            vx.append(-velocity*np.sin((2*np.pi*j)/n))
            vy.append(velocity*np.cos((2*np.pi*j)/n))
            vz.append(0.0)


    x[299:],y[299:],z[299:]=rotation(x[299:],y[299:],z[299:],1.0,0.0,0.0,15.0)
    vx[299:],vy[299:],vz[299:]=rotation(vx[299:],vy[299:],vz[299:],1.0,0.0,0.0,15.0)

    #x[299:],y[299:],z[299:]=rotation(x[299:],y[299:],z[299:],1.0,0.0,0.0,90.0)
    #vx[299:],vy[299:],vz[299:]=rotation(vx[299:],vy[299:],vz[299:],1.0,0.0,0.0,90.0)


    #vx[1],vy[1],vz[1]=rotation([vx[1]],[vy[1]],[vz[1]],1.0,0.0,0.0,60.0)
    #x[299:],y[299:],z[299:]=rotation(x[299:],y[299:],z[299:],0.0,0.0,1.0,90.0)
    #vx[299:],vy[299:],vz[299:]=rotation(vx[299:],vy[299:],vz[299:],0.0,0.0,1.0,90.0)



    x[299:]=[p+Ra for p in x[299:]]
    vy[299:]=[p-vel for p in vy[299:]]
    #print len(x),len(y),len(z)

    return (x,y,z,vx,vy,vz)

def main():
    #n,t=(raw_input('>> N, T ').split())
    t=(raw_input('>>T ').split())
    #n=np.int64(n)
    n=596
    t=np.float128(t)

    x,y,z,vx,vy,vz=init(n)

    N=np.int64(math.ceil(t/1))


    f=open('Data.csv','w')
    with open('Data.csv', 'wb') as fp:
        a = csv.writer(fp)

        for i in range(0,N):
            for j in range(0,n):
                #print i,j
                values=[]
                values.append([x[j],y[j],z[j]])
                a.writerows(values)

            x,y,z,vx,vy,vz=LeapState(x,y,z,vx,vy,vz,n)



    f.close()
main()
