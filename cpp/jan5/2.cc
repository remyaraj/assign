/*
 *Templates that accept more than 1 type parameter
 */
#include <iostream>
using namespace std;

template <class T, class U>
T Getmin(T a, U b)
{
	return(a<b?a:b);
}

int main()
{
	int a,b;
	float c,d;
	cout << "Enter numbers of type int"<< endl;
	cin >> a >> b;
	cout << "Enter the numbers of type float" << endl;
	cin >> c >> d;
	cout << "First test : "<< Getmin<int,float>(a,c)<< endl;
	cout << "second test : "<< Getmin<int,long>(b,d)<< endl;
	return 0;
}
