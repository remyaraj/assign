/*
 * Destructors : "~"at the front  
 *					opposit to constr
 *					No return type
 */

#include <iostream>
#include <new>

using namespace std;

class Crect{
		int *width, *height;
	public:
		Crect(int ,int );
		~Crect();
		int area(){return(*width * *height);}
};

Crect::Crect(int a, int b)
{
	width = new(nothrow)int;
	height =  new(nothrow)int;
	*width = a;
	*height = b;
}

Crect::~Crect()
{
	delete width;
	delete height;
}

int main()
{
	int a,b;
	cout << "Enter the numbers" << endl;
	cin >> a >> b;
	Crect rec(a,b);
	cout <<"area = "<<rec.area()<<endl;
	return 0;
}
