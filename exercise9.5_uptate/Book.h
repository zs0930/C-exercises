#ifndef Book_h
#define Book_h

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

#endif
