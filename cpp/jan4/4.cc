/*
 *pointers to classes
 */

#include <iostream>
using namespace std;

class Crect
{
		int width, height;
	public:
		Crect(int, int);
		int area(){return(width*height);}
};

Crect::Crect(int a, int b)
{
	width = a;
	height = b;
}

int main()
{
	int a,b;
	cout << "Enter the numbers"<<endl;
	cin >> a >> b;
	Crect *c;
	c = new Crect(a,b);
	cout << "area = "<<c->area()<<endl;
	delete c;
	return 0;
}
