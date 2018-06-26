//solve quadratic equation with real roots

#include "std_lib_facilities.h"
#include <math.h>

vector<double> solve_qua (double a, double b, double c)
{
	vector<double> root = {};
	double delta = b*b-4*a*c;
	if (delta<0)
	{
		throw delta;
	}

	else if (delta==0)
	{
		root.push_back(-b/(2*a));
	}

	else
	{
		root.push_back((-b+sqrt(delta))/(2*a));
		root.push_back((-b-sqrt(delta))/(2*a));
	}

	return root;
}

int main()
{
	double a,b,c;
	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;
	cout<<"Enter c: ";
	cin>>c;

	try
	{
		vector<double> root = {};
		root = solve_qua(a,b,c);
		
		if(root.size()==1)
		{
			cout<<"x1 = x2 = "<<root[0]<<endl;
		}
		else
		{
			cout<<"x1 = "<<root[0]<<" x2 = "<<root[1]<<endl;
		}
	}

	catch (double)
	{
		cerr<<"delta<0, no real root"<<endl;
		return 1;
	}

	return 0;
}
