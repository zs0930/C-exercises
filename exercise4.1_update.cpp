//Bleep out dislike words

#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> dislike;
	dislike.push_back("one");
	dislike.push_back("two");
	dislike.push_back("three");
	dislike.push_back("four");

	std::string input;
	std::cout<<"Please enter a word\n";
	std::cin>>input;

	bool dislike_word=false;

	for (const auto& d:dislike)
		if (input==d) dislike_word=true;

	if (dislike_word) std::cout<<"BLEEP\n";
	else std::cout<<input<<"\n";
}

