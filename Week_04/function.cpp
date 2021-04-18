#include <iostream>
#include <functional>

int sum (int x,int y)
{
	return x+y;
}

struct add_x
{
	add_x(int val):x(val){}
	int operator() (int y) const{return x+y;}
private:
	int x;
};

int main()
{

	add_x add42(42);
	int i = add42(0);
	int j = add42(12);

	std::cout << i << std::endl;
	std::cout << j << std::endl;


	return 0;
}