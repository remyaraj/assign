#include <iostream>
using namespace std;

class sample{
		int data;
	public:
		void fun1()
		{
			data = 15;
		}
		void fun2()
		{
			cout<<data<<endl;
		}
};

int main()
{
	sample a;
	sample b;
	a.fun1();
	a.fun2();
	b.fun2();
	return 0;
}
