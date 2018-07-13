#include <iostream>
#include <string>

//to connect C-style strings p1 and p1 with p3

char* cat_dot(const char* p1, const char* p2, const char* p3)
{
	char* p = new char[1];
	int count1 = 0;
	char pick = '0';

	while(pick!='\0')
	{
		pick = p1[count1];
		if(pick=='\0') break;
		p[count1] = pick;
		count1 ++;
		char* q = new char[count1+1];
		for (int i=0;i<count1;i++) q[i] = p[i];
		q[count1] = '\0';
		delete[] p;
		p = q;
	}

	int count3 = 0;
	pick = '0';

	while(pick!='\0')
	{
		pick = p3[count3];
		if(pick=='\0') break;
		p[count1+count3] = pick;
		count3 ++;
		char* q = new char[count1+count3+1];
		for (int i=0;i<count1+count3;i++) q[i] = p[i];
		q[count1+count3] = '\0';
		delete[] p;
		p = q;
	}

	int count2 = 0;
	pick = '0';

	while(pick!='\0')
	{
		pick = p2[count2];
		if(pick=='\0') break;
		p[count1+count3+count2] = pick;
		count2 ++;
		char* q = new char[count1+count3+count2+1];
		for(int i=0;i<count1+count3+count2;i++) q[i] = p[i];
		q[count1+count3+count2] = '\0';
		delete[] p;
		p = q;
	}

	return p;
}

int main()
{
	const char* c1 = "Billie";
	const char* c2 = "Jean";
	const char* c3 = "--";
	char* jointed = cat_dot(c1,c2,c3);
	std::cout<<jointed<<'\n';
}
