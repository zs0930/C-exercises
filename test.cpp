#include <iostream>
#include <string>

int main()
{
	std::string a = "Hello, World!";
	std::string* p = &a;
	char* q = &a[0];
	char* t = new char[5];
	char* s = &q[2];
	t[0] = q[0];
	t[1] = q[5];
	t[3] = q[7];
	std::cout<<p<<'\n'<<*p<<'\n'<<q<<'\n'<<*(q+1)<<'\n'<<t<<'\n'<<*(t+3)<<'\n'<<s<<'\n'<<*s<<'\n';
}


