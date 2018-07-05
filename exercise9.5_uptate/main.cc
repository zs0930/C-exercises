#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

int main()
{
	Book test("1111-22322-3533-k","Soil","Soga","06/25/2018",true);
	std::cout<<test.print_title()<<"\n"<<test.print_author()<<"\n"<<test.state()<<"\n";
	test.check_out();
	std::cout<<test.state()<<"\n";
}

