/*
 *class templates : 
 *
 * If the function defintion is outside the class again the template definiton has to be used,
 */

#include <iostream>
using namespace std;
	
template <class T>
class myfrnd{
		T num1,num2;
	public:
		void set_val(T a,T b)
		{
			num1 = a;
			num2 = b;
		}
		T Getmax();
};

template <class T>
T myfrnd<T>::Getmax()
{
	return(num1>num2?num1:num2);
}

int main()
{
	int a,b;
	float c,d;
	myfrnd <int>obj1;
	myfrnd <float>obj2;
	cout << "Enter the numbers of type int"<< endl;
	cin >> a >> b;
	cout << "Enter the values of type float" << endl;
	cin >> c >> d;
	obj1.set_val(a,b);
	obj2.set_val(c,d);
	cout << "First test : "<< obj1.Getmax()<<endl;
	cout <<"Second test : "<< obj2.Getmax()<<endl;
	return 0;
}
