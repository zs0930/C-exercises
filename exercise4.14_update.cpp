//to find all the prime number between 1 and input value using Sieve of Eratoshenes.

#include <iostream>
#include <vector>

int main()
{
	int max_number = 2;
	std::cout<<"Please enter the upper bound (>=2): ";
	std::cin>>max_number;

	std::vector<int> prime;

	//find sequence from 2 and input value
	for (int i=0;i<=(max_number-2);++i) prime.push_back(i+2);

	int max_prime = prime.at(0);

	while (prime.at(prime.size()-1)>=max_prime*max_prime)
	{
		std::vector<int> multiples {};

		//find multiples of this max_prime
		for (int i=0;i<prime.size();++i)
			if (prime.at(i)%max_prime==0 && prime.at(i)!=max_prime) multiples.push_back(prime.at(i));

		//find position of multiples in vector prime
		std::vector<int> seq {};
		for (int i=0;i<prime.size();++i)
			for (int j=0;j<multiples.size();++j)
				if (prime.at(i)==multiples.at(j)) seq.push_back(i);

		//remove multiples of this max_prime from vector prime
		for (int i=(seq.size()-1);i>=0;--i)
			prime.erase(prime.begin()+seq.at(i));

		//find the next max_prime
		for (int i=0;i<prime.size();++i)
		{
			if (prime.at(i)==max_prime)
			{
				max_prime=prime.at(i+1);
				break;
			}
		}
	}

	std::cout<<"the prime numbers between 1 and "<<max_number<<" are: \n";
	for (int i=0;i<prime.size();++i) std::cout<<prime.at(i)<<";";
	std::cout<<"\n";
}
