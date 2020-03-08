//44374
//4x^2+7x+3
#include <math.h>
#include <iostream>

#define dok 0.01

using namespace std;

double* wyroznikizerowe(double a=4,double b=7,double c=3)
{
	double* wyniki = new double[3];
	wyniki[0]=b*b-4*a*c;
	if(wyniki[0]< -dok)
	{
		wyniki[1]=wyniki[2]=sqrt(-1);
	}
	else if(wyniki[0]>dok)
	{
		wyniki[1]=(-b-sqrt(wyniki[0]))/(2*a);
		wyniki[2]=(-b+sqrt(wyniki[0]))/(2*a);
	}
	else
	{
		wyniki[1]=wyniki[2]=(-b)/(2*a);
	}
	return wyniki;
}

int main()
{
	double* wyniki=wyroznikizerowe();
	cout<<wyniki[0]<<" "<<wyniki[1]<<" "<<wyniki[2];
	return 0;
}
