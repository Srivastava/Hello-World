import time
import numpy as np
import matplotlib.pyplot as plt


x,y,v_0,angle=(raw_input('>> Input x and y corrdinates and velocity and angle').split())

x_0=float(x)
y_0=float(y)


v_0=float(v_0)
angle=float(angle)

vx_0=v_0*np.cos(angle*np.pi/180.0)
vy_0=v_0*np.sin(angle*np.pi/180.0)

print(vx_0, vy_0)

a_x=0
a_y=-9.8
t=0

Range=(-v_0*v_0/a_y)*np.sin(2*angle*np.pi/180.0)
T=2*v_0*np.sin(angle*np.pi/180.0)
print(Range)
print(x)
print(T)

plt.ion()
plt.show()

while(t<=T):
    print(x_0,y_0,vx_0,vy_0,t)
    x_0+=vx_0*t+0.5*a_x*t*t
    y_0+=vy_0*t+0.5*a_y*t*t
    vy_0+=a_y*t
    t=0.01
    plt.plot(x_0,y_0,'or')
    plt.draw()
    time.sleep(0.005)

plt.show(block=True)

'''# evenly sampled time at 200ms intervals
t = np.arange(0., 5., 0.2)

# red dashes, blue squares and green triangles
plt.plot(t, t, 'r--', t, t**2, 'bs', t, t**3, 'g^')
plt.show()'''
