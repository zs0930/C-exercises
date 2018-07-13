#include <iostream>

//read individual characters into an array allocated on the free store until mark !

int main()
{
	char* p = new char[1];
	char input;
	int count = 1;

	while(std::cin>>input)
	{
		if(input=='!') break;
		p[count-1] = input;
		count ++;
		char* q = new char[count];
		for(int i=0;i<count-1;i++) q[i] = p[i];
		q[count-1] = '\0';
		delete[] p;
		p = q;
	}

	std::cout<<p<<'\n';
}


