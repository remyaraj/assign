/*
 *Doubt... error pgm
 */ 
#include <iostream>
using namespace std;

template <class T>
class operations{
		T num1,num2;
	public:
		void set_val(T ,T );
		T add(){return(num1+num2);}
		T mul(){return(num1 * num2);}
};

template <>
class operations<int>{
		int num1,num2;
	public:
		void set_val(int,int);
		int add(){return(num1+num2);}
		int mul(){return(num1*num2);}
		int mod(){return(num1%num2);}
};

template <class T>
void operations<T>::set_val(T a,T b)
{
	num1 = a;
	num2 = b;
}


int main()
{
	int a,b;
	float c,d;
	cout << "Enter the numbers of type int" << endl;
	cin >> a >> b;
	cout << "Enter the numbers of type float"<<endl;
	cin >> c >> d;	
	operations <int> obj1;
	operations <float> obj2;
	obj1.set_val(a,b);
	obj2.set_val(c,d);
	cout << "template specialization example : "<<obj1.mod()<<endl;
	cout << "No specialisation : "<< obj2.add()<<endl;
	return 0;
}
