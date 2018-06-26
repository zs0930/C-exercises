//to find all the prime number between 1 and input value using Sieve of Eratoshenes.

#include "std_lib_facilities.h"

int main()
{
	int max_number = 2;
	cout<<"Please enter the upper bound (>=2): ";
	cin>>max_number;

	vector<int> prime;

	//find sequence from 2 and input value
	for (int i=0;i<=(max_number-2);++i)
	{
		prime.push_back(i+2);
	}

	int max_prime = prime[0];

	while (prime[prime.size()-1]>=max_prime*max_prime)
	{
		vector<int> multiples {};

		//find multiples of this max_prime
		for (int i=0;i<prime.size();++i)
		{
			if (prime[i]%max_prime==0 && prime[i]!=max_prime)
			{
				multiples.push_back(prime[i]);
			}
		}

		//find position of multiples in vector prime
		vector<int> seq {};

		for (int i=0;i<prime.size();++i)
		{
			for (int j=0;j<multiples.size();++j)
			{
				if (prime[i]==multiples[j])
				{
					seq.push_back(i);
				}
			}
		}

		//remove multiples of this max_prime from vector prime
		for (int i=(seq.size()-1);i>=0;--i)
		{
			prime.erase(prime.begin()+seq[i]);
		}

		//find the next max_prime
		for (int i=0;i<prime.size();++i)
		{
			if (prime[i]==max_prime)
			{
				max_prime=prime[i+1];
				break;
			}
		}
	}

	
	cout<<"the prime numbers between 1 and "<<max_number<<" are: "<<endl;
	for (int i=0;i<=(prime.size()-1);++i)
	{
		cout<<prime[i]<<";";
	}

	cout<<endl;

	return 0;
}
