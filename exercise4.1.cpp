//Bleep out dislike words

#include "std_lib_facilities.h"

int main()
{
	vector<string> dislike;
	dislike.push_back("one");
	dislike.push_back("two");
	dislike.push_back("three");
	dislike.push_back("four");

	string input;
	cout<<"Please enter a word"<<endl;
	cin>>input;

	bool dislike_word=false;

	for (int i=0;i<dislike.size();++i)
	{
		if (input==dislike[i])
		{
			dislike_word=true;
		}
	}

	if (dislike_word)
	{
		cout<<"BLEEP"<<endl;
	}
	else
	{
		cout<<input<<endl;
	}

	return 0;
}

