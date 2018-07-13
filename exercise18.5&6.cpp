#include <iostream>
#include <string>

std::string cat_dot(const std::string s1, const std::string s2, const std::string s3)
{
	std::string a = s1;
	std::string b = s2;
	std::string c = s3;
	return a + c + b;
}

int main()
{
	std::string str1 = "Billie";
	std::string str2 = "Jean";
	std::string str3 = "-";
	std::string jointed = cat_dot(str1,str2,str3);
	std::cout<<jointed<<'\n';
}
