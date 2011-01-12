/*
 *sequence templates
 *
 * default values can be assigned like template <class T=int , int 5>
 *
 * so on  declaring the default object like qu<> obj1 will take this default value
 */

#include <iostream>
using namespace std;

template <class T, int N>
class qu{
		T mem[N];
	public:
		void set_mem(int, T);
		T get_mem(int);
};

template <class T, int N>
void qu<T,N>::set_mem(int pos, T val)
{
	mem[pos] = val;
}

template <class T, int N>
T qu<T,N>::get_mem(int pos)
{
	return mem[pos];
}

int main()
{
	int a;
	float b;
	qu<int,5> obj1;
	qu<float,3> obj2;
	cout << "Enter the number of type int : "<<endl;
	cin >> a;
	cout << "Enter the number of type float "<< endl;
	cin >> b;
	obj1.set_mem(2,a);
	obj2.set_mem(1,b);
	cout << "Test value : "<< obj1.get_mem(2)<<endl;
	cout << "Test value2 : "<<obj2.get_mem(1)<<endl;
	return 0;
}
