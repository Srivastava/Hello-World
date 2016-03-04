import sys
import time
import math
import numpy as np
import matplotlib.pyplot as plt
import csv
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.animation as animation

#GM =0.00029632889
GM =1E-3
GMm =10E-12
GMS=8.46611639e-8
print GMm


def accel(x,y,z,n):
    ax=[]
    ay=[]
    az=[]

    for i in range (0,n):
        aX=0
        aY=0
        aZ=0

        for j in range(0,n):


            if(i!=j):
                dist=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))**(-1.5)

                aX+=-GM*(x[i]-x[j])*dist
                aY+=-GM*(y[i]-y[j])*dist
                aZ+=-GM*(z[i]-z[j])*dist


        ax.append(aX)
        ay.append(aY)
        az.append(aZ)

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
'''def animate(i,data):
    for j in range(0,n):
        ax1.plot([data[j][0]],[data[j][1]],[data[j][2]],linestyle='none', marker='o', markersize=50,color='r')'''


def init(n):
    x=[]
    y=[]
    z=[]
    vx=[]
    vy=[]
    vz=[]




    for i in range(0,n):
        x1,x2,x3,x4,x5,x6,x7=np.random.uniform(0.0,1.0,7)
        #print x1,x2,x3,x4,x5,x6,x7
        r=(x1**(-2.0/3.0)-1)**(-0.5)

        zp=(1-2*x2)*r
        xp=((r*r-zp*zp)**(0.5))*np.cos(2*np.pi*x3)
        yp=((r*r-zp*zp)**(0.5))*np.sin(2*np.pi*x3)


        x.append(xp)
        y.append(yp)
        z.append(zp)

        Ve=(2**(0.5))*(1+r*r)*(-0.25)

        while(0.1*x5>=x4*x4*(1-x4*x4)**3.5):
            x4,x5=np.random.uniform(0.0,1.0,2)

        q=x4
        V=Ve*q

        vpz=(1-2*x6)*V
        vpx=((V*V-vpz*vpz)**(0.5))*np.cos(2*np.pi*x7)
        vpy=((V*V-vpz*vpz)**(0.5))*np.sin(2*np.pi*x7)

        vx.append(vpx)
        vy.append(vpy)
        vz.append(vpz)

    #print x[0],y[0]
    return (x,y,z,vx,vy,vz)


Planets=['All Planets','Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus','Neptune','Pluto']
def main():
    n,t=(raw_input('>> N, T ').split())
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

    #print data
    fig = plt.figure(0)
    ax1=Axes3D(fig)

    #fig2 = plt.figure(1)
    #ax2=Axes3D(fig2)
    #ax2.plot(data['x'],data['y'],0, color='r',label=Planets[1])
    #plt.show()
    plt.title(Planets[1])
    xLabel = ax1.set_xlabel('X Au')
    yLabel = ax1.set_ylabel('Y Au')
    zLabel = ax1.set_zlabel('Z Au')

    ax1.set_xlim(-7.8e-2,7.8e-2)
    ax1.set_ylim(-7.8e-2,7.8e-2)





    p=np.int64(t)
    #for i in range(len(data)):
        #animate(i)
    ax1.hold(False)
    def animate(i):
        #print i
        plt.cla()
        ax1.grid(b=False)
        ax1.set_xticks([])
        ax1.set_yticks([])
        ax1.set_zticks([])



        #ax1.hold(False)
        #print i
        #for j in range(i*n,(i+1)*n):
        plt.hold(True)
        aX=data['x']
        aY=data['y']
        aZ=data['z']



        #print j
        ax1.plot(aX[i*n:(i+1)*n],aY[i*n:(i+1)*n],aZ[i*n:(i+1)*n],linestyle='none', marker='o', markersize=10,c='r')
            #plt.hold(False)
        #plt.hold(False)
    ani = animation.FuncAnimation(fig, animate,np.int64(t), interval=10,blit=False,repeat=True)

    ax1.axis('off')
    plt.show();

    #fig.savefig(Planets[1]+'.png',bbox_inches='tight')


main()
