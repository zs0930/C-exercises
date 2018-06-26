#include "std_lib_facilities.h"

class Book {
	private:
		string ISBN;
		string title;
		string author;
		string copyright_date;
		bool stored;
		bool check_ISBN();

	public:
		Book (string ISBN,string title,string author,string copyright_date,bool stored);
		string print_ISBN() {return ISBN;}
		string print_title() {return title;}
		string print_author() {return author;}
		string print_copyright_date() {return copyright_date;}
		string state() {if(stored){return "is not checked out";}
			else {return "is checked out";}}
		void check_out() {stored=false;}
		void check_in() {stored=true;}
		class Invalid_ISBN {};

};

Book::Book(string ISBN,string title,string author,string copyright_date,bool stored)
	:ISBN{ISBN},title{title},author{author},copyright_date{copyright_date},stored{stored}
{	
	if(!check_ISBN()) throw Invalid_ISBN{};
}

bool Book::check_ISBN()
{
	int hyphen = 0;
	vector<int> position = {};
	position.push_back(0);

	for (int i=1;i<ISBN.size();++i)
	{
		if(ISBN[i]=='-')
		{
			++hyphen;
			position.push_back(i-1);
			position.push_back(i+1);
		}
	}


	position.push_back(ISBN.size()-1);

	if(hyphen!=3){return false;}

	vector<string> ISBN_part = {};

	for (int i=0;i<=6;i=i+2)
	{
		string part = ISBN.substr(position[i],(position[i+1]-position[i]+1));
		ISBN_part.push_back(part);
	}

	string num = "0123456789";
	for (int i=0;i<ISBN_part.size()-1;++i)
	{
		string part = ISBN_part[i];
		cout<<part<<endl;
		int count = 0;
		for (int j=0;j<part.size();++j)
		{
			for (int k=0;k<10;++k)
			{
				if(part[j]==num[k]){++count;}
			}
		}
		if(count!=part.size()) {return false;}
	}

	string last_part = ISBN_part[3];
	if(last_part.size()!=1) {return false;}
	string last = "0123456789abcdefghijklmnopqrstuvwxyz";
	int count = 0;
	for (int i=0;i<36;++i)
	{
		if(last_part[0]==last[i]) {++count;}
	}
	if(count!=1) {return false;}

	return true;
}


int main()
{
	Book test("1111-22322-3533-k","Soil","Soga","06/25/2018",true);
	cout<<test.print_title()<<endl<<test.print_author()<<endl<<test.state()<<endl;
	test.check_out();
	cout<<test.state()<<endl;

	return 0;
}

