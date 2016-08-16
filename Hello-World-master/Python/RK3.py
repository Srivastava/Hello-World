import scipy as sp
import numpy as np
import matplotlib.pyplot as plt

dx=0.001
dt=0.01
timeStep=10

Ntime=int(timeStep/dt)

nx=int(1/dx)
a=0
u=0.5

Ti=sp.zeros([nx])
T=sp.zeros([nx])

dx2=dx**2

for i in range(nx):
    if(i*dx<=0.5 and i*dx>=0.2):
        Ti[i]=np.sin(20*np.pi*i*dx)+np.sin(10*np.pi*i*dx)
Ti[0]=2
Ti[nx-1]=0

def evolve(T,Ti):
    global nx,a
    k1=sp.zeros([nx])
    k2=sp.zeros([nx])
    k3=sp.zeros([nx])

    #k1[1:-1]=dt*a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*(Ti[2 : ]+Ti[:-2])/(2*dx)
    #k2[1:-1]=dt*(T[1:-1]+dt/2)
    #k1[1:-1]=dt*(T[1:-1]+dt)
    Ti[0]=2
    T[1:-1]=Ti[1:-1]+((1/dx2)*a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2]))- (1/(2*dx))*u*dt*(Ti[2 : ]+Ti[:-2])
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*((Ti[2 : ]+Ti[:-2])/(2*dx))
    #Ti = sp.copy(T)
    return T

for m in range(1, timeStep+1):
    Ti=evolve(T,Ti)
    #print Ti
    #print "Computing u for m =", m

x=np.linspace(0, 1, nx)

plt.xlabel('x')
plt.ylabel('T(x)')
plt.title('Plot of Pure difussion for Explicit Euler in Time and 2nd Order Central Difference Scheme in Space ')

plt.plot(x,Ti)
plt.show()
