/*
 * LEAPINT.C: program to integrate hamiltonian system using leapfrog.
 */

#include <math.h>
#include<stdio.h>

#define MAXPNT  5000				/* maximum number of points */
#define GM 0.00029632889
#define GMS 8.46611639e-8
//#define Gm 2.9632889e-12
#define Gm 2.9632889e-5
#define GE 13144183.237

#define PI 3.14159265359

void leapstep();				/* routine to take one step */

void accel();					/* accel. for harmonic osc. */

void printstate();				/* print out system state   */

void main(argc, argv)
int argc;
char *argv[];
{
    int n, mstep, nout, nstep;
    double x[MAXPNT],y[MAXPNT], vx[MAXPNT],vy[MAXPNT], tnow, dt;

    /* first, set up initial conditions */

    n = 10;					/* set number of points     */

    float radius=7.8e-4;
    float velocity=sqrt(GMS/(double)radius)-0.000418;
    printf("%f",velocity);
    double angleI=2*PI/(double)n;
    //x[0]=-9.553654538071938E-01;y[0]= -3.188678205864556E-01;
 //vx[0]=4.259243792590239E-03; vy[0]=-1.819435357082918E-02;
     int countP;
    for(countP=0;countP<n;++countP)
    {
        float angle=countP*angleI;
        x[countP]=radius*cos(angle);
        y[countP]=radius*sin(angle);

        //printf("%f\n",x[countP]);

        vx[countP]=-velocity*sin(angle);
        vy[countP]=velocity*cos(angle);
    }

    tnow = 0.0;					/* set initial time         */

    /* next, set integration parameters */

    mstep = 900;				/* number of steps to take  */
    nout = 1;					/* steps between outputs    */
    dt = 5;				/* timestep for integration */
    /* now, loop performing integration */

    for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
	if (nstep % nout == 0)			/* if time to output state  */
	    printstate(x,y, vx,vy, n, tnow);		/* then call output routine */
	leapstep(x,y, vx,vy, n, dt);			/* take integration step    */
	tnow = tnow + dt;			/* and update value of time */
    }
    if (mstep % nout == 0)			/* if last output wanted    */
	printstate(x,y, vx,vy, n, tnow);		/* then output last step    */
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(x,y, vx,vy, n, dt)
double x[];
double y[];
				/* positions of all points  */
double vx[];
double vy[];
					/* velocities of all points */
int n;						/* number of points         */
double dt;					/* timestep for integration */
{
    int i;
    double ax[MAXPNT],ay[MAXPNT];

    accel(ax,ay, x,y, n);				/* call acceleration code   */
    for (i = 0; i < n; i++)
    {		/* loop over all points...  */
	vx[i] = vx[i] + 0.5 * dt * ax[i];
	vy[i] = vy[i] + 0.5 * dt * ay[i];

	}		/* advance vel by half-step */
    for (i = 0; i < n; i++)	{		/* loop over points again...*/
	x[i] = x[i] + dt * vx[i];
	y[i] = y[i] + dt * vy[i];

	}		/* advance pos by full-step */
    accel(ax,ay, x,y, n);				/* call acceleration code   */
    for (i = 0; i < n; i++)
    {		/* loop over all points...  */
	vx[i] = vx[i] + 0.5 * dt * ax[i];
	vy[i] = vy[i] + 0.5 * dt * ay[i];

	}	/* and complete vel. step   */
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(ax,ay, x,y, n)
double ax[];
double ay[];
					/* accelerations of points  */
double x[];
double y[];
				/* positions of points      */
int n;						/* number of points         */
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {                               /* loop over all points...  */
        double temp=pow(x[i]*x[i]+y[i]*y[i],3.0/2.0);
        ax[i]	=-(GMS/temp)*x[i];
	                               /* loop over all points...  */

        ay[i]	=-(GMS/temp)*y[i];
	                               /* loop over all points...  */
        for(j=0;j<n;++j)
        {
            if(j!=i){
            float distanceX=(x[i]-x[j]) *(x[i]-x[j]);
            float distanceY=(y[i]-y[j]) *(y[i]-y[j]);

            float distance=distanceX+distanceY;
           //printf("%f",ax[i]);
            ax[i]=-(x[i]-x[j])*(Gm/((distance*sqrt(distance))))+ax[i];
            ay[i]=-(y[i]-y[j])*(Gm/((distance*sqrt(distance))))+ay[i];
        }
        }

	}
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(x,y, vx,vy, n, tnow)
double x[];
double y[];
				/* positions of all points  */
double vx[];
double vy[];
					/* velocities of all points */
int n;						/* number of points         */
double tnow;					/* current value of time    */
{
    int i;

    for (i = 0; i < n; i++)			/* loop over all points...  */
	printf("%8.4f,%4d,%12.6f,%12.6f, %d\n", tnow, i, x[i], y[i],n);

	/*FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }*/

    //int j;
   /* for (j = 0; j < n; j++)
    {
        //fprintf(f, "%f         %f        %f    %f         %f        %f            %f\n", x[j],y[j],z[j], vx[j], vy[j], tnow);
        fprintf(f, "%f         %f        %f\n", j,x[j],y[j]);
    }*/
}
