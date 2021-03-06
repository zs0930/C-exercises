#include <iostream>
#include <string>
#include <vector>

class Book {
	
	public:
		Book (std::string isbn,std::string title,std::string author,std::string copyright_date,bool stored);
		std::string print_isbn() {return isbn;}
		std::string print_title() {return title;}
		std::string print_author() {return author;}
		std::string print_copyright_date() {return copyright_date;}
		std::string state() {if(stored){return "is not checked out";}
			else {return "is checked out";}}
		void check_out() {stored=false;}
		void check_in() {stored=true;}
		class Invalid_isbn {};
	
	private:
		std::string isbn;
		std::string title;
		std::string author;
		std::string copyright_date;
		bool stored;
		bool check_isbn();
};

Book::Book(std::string isbn,std::string title,std::string author,std::string copyright_date,bool stored)
	:isbn{isbn},title{title},author{author},copyright_date{copyright_date},stored{stored}
{	
	if(!check_isbn()) throw Invalid_isbn{};
}

bool Book::check_isbn()
{
	int hyphen = 0;
	std::vector<int> position = {};
	position.push_back(0);

	for (int i=1;i<isbn.size();++i)
	{
		if(isbn[i]=='-')
		{
			++hyphen;
			position.push_back(i-1);
			position.push_back(i+1);
		}
	}


	position.push_back(isbn.size()-1);

	int num_of_hyphen = 3;
	int num_of_npart = 3;
	int position_of_xpart = 3;

	if(hyphen!=num_of_hyphen){return false;}

	std::vector<std::string> isbn_part = {};

	for (int i=0;i<=num_of_npart*2;i=i+2)
	{
		std::string part = isbn.substr(position.at(i),(position.at(i+1)-position.at(i)+1));
		isbn_part.push_back(part);
	}

	for (int i=0;i<isbn_part.size()-1;++i)
		for (int j=0;j<isbn_part.at(i).size();++j)
			if (isdigit(isbn_part.at(i).at(j))==0) return false;

	if (isbn_part.at(position_of_xpart).size()!=1) return false;
	char last_part = isbn_part.at(position_of_xpart).at(0);
	if (isdigit(last_part)==0 && isalpha(last_part)==0) return false;

	return true;
}


int main()
{
	Book test("1111-22322-3533-k","Soil","Soga","06/25/2018",true);
	std::cout<<test.print_title()<<"\n"<<test.print_author()<<"\n"<<test.state()<<"\n";
	test.check_out();
	std::cout<<test.state()<<"\n";
}

