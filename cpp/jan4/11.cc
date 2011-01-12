/*
 * PURE VIRTUAL Functions
 *
 *Abstract base classes : No instances can be created
 *						  but pointers to base class is valid
 * 
 */
#include <iostream>
#include <new>
using namespace std;

class Polygon{
	protected:
		int height,width;
	public:
		void set(int,int);
		virtual int area()=0;
};

class Crect:public Polygon{
	public:
		int area(){return(height*width);}
};

class Ctri:public Polygon{
	public:
		int area(){return(0.5*height*width);}
};

void Polygon::set(int a, int b)
{
	height = a;
	width = b;
}

int main()
{
	int a,b;
	Polygon *p1;
	Polygon *p2;
	p1 = new(nothrow)Crect;
	p2 = new(nothrow)Ctri;
	cout << "Enter the height and width"<<endl;
	cin>>a>>b;
	p1->set(a,b);
	p2->set(a,b);
	cout<<"area of rect = "<<p1->area()<<endl;
	cout<<"area of triangl = "<<p2->area()<<endl;
	delete p1;
	delete p2;
	return 0;
}
