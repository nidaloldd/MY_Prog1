#include "lib_files/std_lib_facilities.h"

//01
int fac(int n) { return n>1 ? n*fac(n-1) : 1;};

int fac1(int n)
{
	int s = 1;
	while(n>1)
	{
		s *= n;
		n--;
	}
	return s;
}


//02
class Fct
{
public:
	Fct();
	
};


int main()
{
	for (int i = 0; i < 20; ++i)
	{
		cout << fac(i) << "->" << fac1(i) << endl;
	}


	return 0;
}