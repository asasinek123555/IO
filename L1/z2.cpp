//44374
//4x^2+7x+3

#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#define dok (1.0/22050.0)

using namespace std;

namespace function
{
	double x(double t)
	{
		return 4*t*t+7*t+3;
	}
	
	double y(double t)
	{
		return 2*pow(x(t),2)+12*cos(t);
	}
	
	double z(double t)
	{
		return sin(2*M_PI*7*t)*x(t)-0.2*log10(abs(y(t))+M_PI);
	}
	
	double u(double t)
	{
		return sqrt(abs(pow(y(t),2)*z(t)))-1.8*sin(0.4*t*z(t)*x(t));
	}
	
	double v(double t)
	{
		if(t<0.22)
		{
			return (1-7*t) *sin((2*M_PI*t*10)/(t+0.4));
		}
		else if(t<0.7)
		{
			return 0.63*t*sin(125*t);
		}
		else
		{
			return pow(t,-0.662)+0.77*sin(8*t);
		}
	}
	
	int N[3]={2,4,47};
	
	double p(double t)
	{
		double sum=0;
		for(int i=0;i<3;i++)
		{
			sum+=((cos(12*t*N[i]*N[i])+cos(16*t*N[i]))/(N[i]*N[i]));
		}
		return sum;
	}
}

using namespace function;

int main()
{
	ofstream wyjscie;
	wyjscie.open("wyniki.txt");
	
	double krok=dok;
	for(double i=0;i<=1;i+=krok)
	{
		//cout<<setw(8)<<i<<setw(11)<<fixed<<x(i)<<setw(11)<<fixed<<y(i)<<setw(11)<<fixed<<z(i)<<setw(12)<<fixed<<u(i)<<setw(10)<<fixed<<v(i)<<setw(11)<<fixed<<yy(i)<<endl;
		wyjscie<<i<<" "<<fixed<<setprecision(20)<<x(i)<<" "<<fixed<<setprecision(20)<<y(i)<<" "<<fixed<<setprecision(20)<<z(i)<<" "<<fixed<<setprecision(20)<<u(i)<<" "<<fixed<<setprecision(20)<<v(i)<<" "<<fixed<<setprecision(20)<<p(i)<<endl;
	}
	wyjscie.close();
	return 0;
}
