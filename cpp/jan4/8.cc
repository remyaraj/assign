/*
 *Multiple inheritance
 */

#include <iostream>
using namespace std;

class height{
	protected:
		int height;
	public:
		void set_ht(int);
};

class base{
	protected:
		int base;
	public:
		void set_bas(int);
};

class rect:public height,public base{
	public:
		int area(){return(height*base);}
		int cuboid_area(){return(area()*6);}
};

void height::set_ht(int a)
{
	height = a;
}

void base::set_bas(int a)
{
	base = a;
}

int main()
{
	int a,b;
	rect rec;
	cout<<"Enter the height and base"<<endl;
	cin >>a>>b;
	rec.set_ht(a);
	rec.set_bas(b);
	cout<<"area = "<<rec.area()<<endl;
	cout<<"cuboid surface area = "<<rec.cuboid_area()<<endl;
	return 0;
}
