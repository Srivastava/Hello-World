#y[i+1] = y[i] + 1.0/6.0 * ( k1 + 4.0*k2 + k3 )

#k1 = h * f(x[i], y[i])
#k2 = h * f(x[i] + h / 2, y[i] + k1 / 2 )
#k3 = h * f(x[i] + h, y[i] - k1 + 2 * k2 )'''


import scipy as sp
import numpy as np
import matplotlib.pyplot as plt
import math as mt

dx=0.01
dt=0.001
xFinal=1
timeStep=100000

nx=int(1/dx)
#a=0.005
a=0.005
u=0.0

Ti=sp.zeros([nx])
T=sp.zeros([nx])

dx2=dx**2

for i in range(nx):
    if(i*dx<=0.5 and i*dx>=0.2):
        Ti[i]=np.sin(20*np.pi*i*dx)+np.sin(10*np.pi*i*dx)
        #Ti[i]=a*np.sin(2*np.pi*i*dx)





def analytical(tval):
    xval=np.linspace(0, xFinal, nx)
    Ta=sp.zeros([nx])

    #Ta[1:-1]=sin(10*pi*x[1:-1])*exp(-100*pi*pi*alpha*tval)+sin(20*pi*x[1:-1])*exp(-400*pi*pi*alpha*tval);

    for i in range(nx):
        if(i*dx<=0.5 and i*dx>=0.2):
            Ta[i]=np.sin(10*np.pi*i*dx)*mt.exp(-100*np.pi*np.pi*a*tval)+np.sin(20*np.pi*i*dx)*mt.exp(-400*np.pi*np.pi*a*tval);

    return Ta


def evolve(T,Ti):
    global nx,a
    k1=sp.zeros([nx])
    k2=sp.zeros([nx])
    k3=sp.zeros([nx])


    Ti[0]=0
    Ti[nx-1]=0
    #k1[1:-1]=a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 - u*0.5*(Ti[2 : ]-Ti[:-2])/(dx)
    #k2[1:-1]=Ti[1:-1]+k1[1:-1]*(8.0/15.0)*dt
    #k3[1:-1]=Ti[1:-1]+dt*(0.25)*k1[1:-1] + (5.0/12.0)*dt*k2[1:-1]
    #k1[1:-1]=dt*(T[1:-1]+dt)

    k1[1:-1]=a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 - u*0.5*(Ti[2 : ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(8.0/15.0)*dt*k1[1:-1]

    k2[1:-1]=a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 - u*0.5*(Ti[2 : ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(5.0/12.0)*dt*k2[1:-1]-(17.0/60.0)*dt*k1[1:-1]

    k3[1:-1]=a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 - u*0.5*(Ti[2 : ]-Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(3.0/4.0)*dt*k3[1:-1]-(5.0/12.0)*dt*k2[1:-1]

    Ti[0]=0
    Ti[nx-1]=0


    #T[1:-1]=Ti[1:-1]+dt*(0.25*k1[1:-1]+0.75*k3[1:-1])
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*dt*(Ti[2 : ]+Ti[:-2])/(2*dx)
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*((Ti[2 : ]+Ti[:-2])/(2*dx))
    #Ti = sp.copy(T)
    return Ti
x=np.linspace(0, xFinal, nx)
fig,ax=plt.subplots()

points, = ax.plot(x,Ti,color='r',label='Numerical Solution')
points1,=ax.plot(x,Ti,color='b',label='Analytical Solution')

ax.legend([points,points1], [points.get_label(),points1.get_label()])
plt.hold(False)

for m in range(0, timeStep):


    Ta=analytical(m*dt)
    Ti=evolve(T,Ti)



    points.set_data(x,Ti)
    points1.set_data(x,Ta)
    #plt.hold(True)




    #plt.hold(False)

    plt.xlabel('x')
    plt.ylabel('T(x)')
    plt.title('Plot of Pure difussion for Explicit Euler in Time and 2nd Order Central Difference Scheme in Space ')

    plt.pause(0.000000005)

    #plt.plot(x,Ti)

    #print "Computing u for m =", m
