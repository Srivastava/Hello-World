#y[i+1] = y[i] + 1.0/6.0 * ( k1 + 4.0*k2 + k3 )

#k1 = h * f(x[i], y[i])
#k2 = h * f(x[i] + h / 2, y[i] + k1 / 2 )
#k3 = h * f(x[i] + h, y[i] - k1 + 2 * k2 )'''


import scipy as sp
import numpy as np
import matplotlib.pyplot as plt

dx=0.01
dt=0.1
timeStep=3

nx=int(1/dx)
#a=0.005
a=0
u=0.5

Ti=sp.zeros([nx])
T=sp.zeros([nx])

dx2=dx**2

for i in range(nx):
    if(i*dx<0.5 and i*dx>0.2):
        Ti[i]=np.sin(20*np.pi*i*dx)+np.sin(10*np.pi*i*dx)
Ti[0]=2
Ti[nx-1]=0

def evolve(T,Ti):
    global nx,a
    k1=sp.zeros([nx])
    k2=sp.zeros([nx])
    k3=sp.zeros([nx])

    k1[1:-1]=dt*a*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*(Ti[2 : ]+Ti[:-2])/(2*dx)
    k2[1:-1]=(k1[1:-1]+dt/2)
    k3[1:-1]=(k2[1:-1]+dt)
    #k1[1:-1]=dt*(T[1:-1]+dt)

    T[1:-1]=Ti[1:-1]+dt*(1.0/6.0)*(k1[1:-1]+4*k2[1:-1]+k3[1:-1])
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*dt*(Ti[2 : ]+Ti[:-2])/(2*dx)
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*((Ti[2 : ]+Ti[:-2])/(2*dx))
    Ti = sp.copy(T)

for m in range(1, timeStep+1):
    evolve(T,Ti)
    #print "Computing u for m =", m

x=np.linspace(0, 1, nx)

plt.xlabel('x')
plt.ylabel('T(x)')
plt.title('Plot of Pure difussion for Explicit Euler in Time and 2nd Order Central Difference Scheme in Space ')

plt.plot(x,Ti)
plt.show()
