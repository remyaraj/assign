//simple class

#include <iostream>
using namespace std;

class Crect{
		int x,y;
	public:
		void set(int, int);
		int area() {return(x*y);}
};

void Crect::set(int a,int b)
{
	x = a;
	y = b;
}

int main()
{
	int a,b;
	Crect rec;
	cout << "Enter the numbers"<< endl;
	cin >>a>>b;
	rec.set(4,7);
	cout<<"area = "<<rec.area()<<endl;
	return 0;
}
