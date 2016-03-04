#y[i+1] = y[i] + 1.0/6.0 * ( k1 + 4.0*k2 + k3 )

#k1 = h * f(x[i], y[i])
#k2 = h * f(x[i] + h / 2, y[i] + k1 / 2 )
#k3 = h * f(x[i] + h, y[i] - k1 + 2 * k2 )'''


import scipy as sp
import numpy as np
import matplotlib.pyplot as plt

dx=0.01

timeFinal=float(100)
#dt=1.0/timeFinal


timeStep=10000
dt=timeFinal/timeStep

nx=int(10/dx)
#a=0.0055
u=0.5

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

    k1[1:-1]=-0.5*(Ti[1 :-1 ]*Ti[1 :-1 ]-Ti[:-2]*Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(8.0/15.0)*dt*k1[1:-1]

    k2[1:-1]=-0.5*(Ti[1 :-1 ]*Ti[1 :-1 ]-Ti[:-2]*Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(5.0/12.0)*dt*k2[1:-1]-(17.0/60.0)*dt*k1[1:-1]

    k3[1:-1]=-0.5*(Ti[1 :-1 ]*Ti[1 :-1 ]-Ti[:-2]*Ti[:-2])/(dx)
    Ti[1:-1]=Ti[1:-1]+(3.0/4.0)*dt*k3[1:-1]-(5.0/12.0)*dt*k2[1:-1]

    #Ti[0]=1
    #Ti[nx-1]=0


    #T[1:-1]=Ti[1:-1]+dt*(0.25*k1[1:-1]+0.75*k3[1:-1])
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*dt*(Ti[2 : ]+Ti[:-2])/(2*dx)
    #T[1:-1]=Ti[1:-1]+a*dt*(Ti[2 : ] - 2*Ti[1:-1] + Ti[:-2])/dx2 + u*((Ti[2 : ]+Ti[:-2])/(2*dx))
    #Ti = sp.copy(T)
    return Ti

x=np.linspace(0, 10, nx)
fig,ax=plt.subplots()

points, = ax.plot(x,Ti,color='r',label='Numerical Solution')
#text=plt.text(0.9,1,"Burgers Equation Using Upwind at t=0",ha='center',va='top',transform = ax.transAxes,fontsize='18')
plt.hold(False)
for m in range(0, timeStep+1):

    Ti=evolve(T,Ti)
    #print Ti

        #plt.hold(True)

    timeEl=m*dt
    plt.xlabel('x')
    plt.ylabel('u(x)')
    plt.grid(True)
    #text.set_text("t=: {0}".format(timeEl))
    #plt.title('Burgers Equation using RK3 in time and 1st Order Upwind in Space')

    if(timeEl==0 or timeEl==0.5 or timeEl==1 or timeEl==1.5 or  timeEl==5 or timeEl==10):
        points.set_data(x,Ti)

        fig.savefig('FigureBurgerUV'+str(timeEl)+'.png',dpi=1200)






        #plt.hold(False)



    plt.pause(0.000000005)

    #print "Computing u for m =", m
