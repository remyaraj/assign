/*
 *constructors :
 *				No return type not even void
 */
#include <iostream>
using namespace std;

class Crect{
		int x,y;
	public:
		Crect(int, int);
		int area() {return(x*y);}
};

Crect::Crect(int a,int b)
{
	x = a;
	y = b;
}

int main()
{
	int a,b;
	cout << "Enter the numbers"<< endl;
	cin >>a>>b;
	Crect rec(a,b);
	cout<<"area = "<<rec.area()<<endl;
	return 0;
}
