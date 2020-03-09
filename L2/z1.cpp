//44374
//EDCBA
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

namespace ton
{
	
	class Prosty
	{
		double A=1.0;
		double F=7.0;
		double fi=M_PI*3;
		
		double s(double t)
		{
			return A*sin(2*M_PI*F*t+fi);
		}
	};
	
}

using namespace ton;

int main()
{
	ofstream wyjscie;
	wyjscie.open(wniki.txt)
	//wyjscie<<;
	wyjscie.close();
	return 0;
}
