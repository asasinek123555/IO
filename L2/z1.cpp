//44374
//EDCBA
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <climits>

using namespace std;

namespace ton
{
	
	class Prosty
	{
		private:
			double A;
			double F;
			double fi;
		public:
			Prosty()
			{
					A=1.0;
					F=7.0;
					fi=M_PI*3;
			}
			double s(double t)
			{
				return A*sin(2*M_PI*F*t+fi);
			}
			short kwantyzuj(double x)
			{
				for(short i=SHRT_MIN;x>-1;i++)
				{
					x-=1.0/(double)SHRT_MAX;
				}
			}
	}Prosty;
	
	class prosty
	{
		private:
			double A;
			double F;
			double fi;
		public:
			prosty()
			{
					A=1.0;
					F=7.0;
					fi=M_PI*3;
			}
			double s(double t)
			{
				return A*sin(2*M_PI*F*t+fi);
			}
			short kwantyzuj(double x)
			{
				for(short i=-pow(2,8);x>-1;i++)
				{
					x-=1.0/(double)pow(2,8);
				}
			}
	}prosty;
	
}

using namespace ton;

int main()
{
	ofstream wyjscie;
	wyjscie.open("wyniki.txt");
	for(double i=0;i<10;i+=0.001)
		wyjscie<<fixed<<i<<" "<<fixed<<Prosty.s(i)<<" "<<fixed<<Prosty.kwantyzuj(Prosty.s(i))<<endl;
	wyjscie.close();
	wyjscie.open("wyniki2.txt");
	for(double i=0;i<10;i+=0.0005)
		wyjscie<<fixed<<i<<" "<<fixed<<prosty.kwantyzuj(prosty.s(i))<<endl;
	wyjscie.close();
	return 0;
}
