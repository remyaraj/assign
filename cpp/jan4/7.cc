/*
 *inheritance of constructors from base class
 * default constructor is invoked
 */

#include <iostream>
using namespace std;

class Mother{

	public:
		Mother(){cout<<"Mother default"<<endl;}
		Mother(int);
};

Mother::Mother(int a)
{
	cout<<"mother with parameters"<<endl;
}

class Son:public Mother{
		int a;
	public:
		Son():Mother(a){cout<<"son"<<endl;}
};

class Daughter:public Mother{
	public:
		Daughter(){cout<<"Daughter"<<endl;}
};

int main()
{
	Son sn;
	Daughter Dr;
	return 0;
}
