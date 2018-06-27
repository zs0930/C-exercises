//solve quadratic equation with real roots

#include <iostream>
#include <math.h>
#include <vector>

std::vector<double> solve_qua (double a, double b, double c)
{
	std::vector<double> root = {};
	double delta = b*b-4*a*c;
	if (delta<0) throw delta;
	else if (delta==0) root.push_back(-b/(2*a));
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
	std::cout<<"Enter a: ";
	std::cin>>a;
	std::cout<<"Enter b: ";
	std::cin>>b;
	std::cout<<"Enter c: ";
	std::cin>>c;

	try
	{
		std::vector<double> root = {};
		root = solve_qua(a,b,c);
		if(root.size()==1) std::cout<<"x1 = x2 = "<<root[0]<<"\n";
		else std::cout<<"x1 = "<<root[0]<<" x2 = "<<root[1]<<"\n";
	}

	catch (double)
	{
		std::cerr<<"delta<0, no real root"<<"\n";
		return 1;
	}
}
