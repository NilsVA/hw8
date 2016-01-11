#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void euler(double*,double*,int,double);



int main()
{
        double e = 0.6;
	double q_1 = 1.0 - e;
	double q_2 = 0;
        double p_1 = 0;
        double p_2 = sqrt((1. + e)/(1. - e));
	double tmax = 20*M_PI;
	double dt = 0.05;                           //M_PI/200;
	int n = tmax/dt;
	
	double q[2];
	double p[2];
	

	q[0]=q_1;q[1]=q_2;
	p[0]=p_1;p[1]=p_2;
	

	euler(q,p,n,dt);
	

	
}

void euler(double* q,double * p , int n, double dt)
{
	double h;
	ofstream output("euler.txt");
	for(int i=1;i<n;i++)
	{
         h = (pow(p[0],2)+pow(p[1],2))/2 - (1./sqrt(pow(q[0],2)+pow(q[1],2)));
	 p[0]=p[0]+dt*(-1.0)*(q[0]/pow(pow(q[0],2)+pow(q[1],2),3./2.));
         p[1]=p[1]+dt*(-1.0)*(q[1]/pow(pow(q[0],2)+pow(q[1],2),3./2.));
	 q[0]=q[0]+dt*p[0];
         q[1]=q[1]+dt*p[1];
	 output << i*dt  << "\t" << q[0] << "\t" << q[1] << "\t" << h << endl;
	}
	output.close();

}
