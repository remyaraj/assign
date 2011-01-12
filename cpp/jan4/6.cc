#include <iostream>
using namespace std;

class Polygon{
	protected:
		int height;
		int width;
	public:
		void set(int ,int );
};

void Polygon::set(int a, int b)
{
	height = a;
	width = b;
}

class Crect:public Polygon{
	public:
		int area(){return(width * height);}
};

class Ctri:public Polygon{
	public:
		int area(){return(0.5*height *width);}
};

int main()
{
	int a,b;
	cout << "Enter the numbers"<<endl;
	cin >> a >> b;
	Crect rec;
	Ctri tri;
	rec.set(a,b);
	tri.set(a,b);
	cout << "area of rect = "<<rec.area()<<endl;
	cout <<"area of tri = "<< tri.area()<<endl;
	return 0;
}
