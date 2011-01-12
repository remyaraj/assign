/*
 *friend class and functions
 */
#include <iostream>
using namespace std;

class Csq;

class Crect{
		int width, height;
	public:
		Crect(){width=0;height=0;};
		Crect(int ,int );
		int area(){return(width * height);}
		void square(Csq);
		friend int perimeter(Crect);
};

int perimeter(Crect a)
{
	return(2 * a.width * a.height);
}

class Csq{
		int side;
	public:
		Csq(int);
		friend class Crect;
};

void Crect::square(Csq a)
{
	width = a.side;
	height = a.side;
}

Csq::Csq(int a)
{
	side = a;
}

Crect::Crect(int a,int b)
{
	width = a;
	height = b;
}
 

int main()
{
	Csq squar(4);
	Crect rec;
	Crect rec1(5,8);
	rec.square(squar);
	cout << "area with rec = "<<rec.area()<<endl;
	cout << "area with rec1 for 1st = "<<rec1.area()<<endl;
	rec1.square(squar);
	cout << "area with rec1 for 2nd = "<<rec1.area()<<endl;
	cout <<"perimeter = "<<perimeter(rec1)<<endl;
	return 0;
}
