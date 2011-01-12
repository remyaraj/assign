/*
 *overloaded functions
 */
#include <iostream>
using namespace std;

int operate(int x,int y)
{
	return x+y;
}

float operate(float x, int y)
{
	return x/y;
}

int main()
{
	int a;
	float b;
	a = operate(5,9);
	b = operate(21,2);
	return 0;
}
