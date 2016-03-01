#y[i+1] = y[i] + 1.0/6.0 * ( k1 + 4.0*k2 + k3 )

#k1 = h * f(x[i], y[i])
#k2 = h * f(x[i] + h / 2, y[i] + k1 / 2 )
#k3 = h * f(x[i] + h, y[i] - k1 + 2 * k2 )'''


import scipy as sp
import numpy as np
import matplotlib.pyplot as plt

dx=0.1
dt=0.001
timeStep=10000

nx=int(10/dx)
#a=0.005

Ti=sp.zeros([nx])
T=sp.zeros([nx])



for i in range(nx):
    if(i*dx<=1 and i*dx>=0):
        Ti[i]=i*dx
        #print Ti[i]
    if(i*dx<=2 and i*dx>1):
        Ti[i]=2-i*dx
        #print Ti[i]
        #Ti[i]=a*np.sin(2*np.pi*i*dx)


x=np.linspace(0, 10, nx)
fig,ax=plt.subplots()

def evolve(T,Ti):
    global nx,a
    k1=sp.zeros([nx])
    k2=sp.zeros([nx])
    k3=sp.zeros([nx])


    #Ti[0]=1
    T#i[nx-1]=0
    #k1[1:-1]=a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 - u*0.5*(Ti[2 : ]-Ti[:-2])/(dx)
    #k2[1:-1]=Ti[1:-1]+k1[1:-1]*(8.0/15.0)*dt
    #k3[1:-1]=Ti[1:-1]+dt*(0.25)*k1[1:-1] + (5.0/12.0)*dt*k2[1:-1]
    #k1[1:-1]=dt*(T[1:-1]+dt)

    k1[1:-1]=(Ti[1 :-1 ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(8.0/15.0)*dt*k1[1:-1]

    k2[1:-1]=(Ti[1 :-1 ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(5.0/12.0)*dt*k2[1:-1]-(17.0/60.0)*dt*k1[1:-1]

    k3[1:-1]=(Ti[1 :-1 ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(3.0/4.0)*dt*k3[1:-1]-(5.0/12.0)*dt*k2[1:-1]

    #Ti[0]=1
    #Ti[nx-1]=0


    #T[1:-1]=Ti[1:-1]+dt*(0.25*k1[1:-1]+0.75*k3[1:-1])
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*dt*(Ti[2 : ]+Ti[:-2])/(2*dx)
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*((Ti[2 : ]+Ti[:-2])/(2*dx))
    #Ti = sp.copy(T)
    return Ti

plt.hold(False)
for m in range(1, timeStep):
    points, = ax.plot(x,Ti)
    Ti=evolve(T,Ti)
    print Ti
    points.set_data(x,Ti)

    plt.xlabel('x')
    plt.ylabel('T(x)')
    plt.title('Plot of Pure difussion for Explicit Euler in Time and 2nd Order Central Difference Scheme in Space ')
    #plt.show()
    plt.pause(0.0000005)

    #plt.plot(x,Ti)

    #print "Computing u for m =", m
