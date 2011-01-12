/*
 *Template usage
 */
#include <iostream>
using namespace std;

template <class T>
T Getmax(T a, T b)
{
	return(a>b?a:b);
}

int main()
{
	int a,b;
	float c,d;
	cout << "Enter the integer numbers"<< endl;
	cin >> a >>b;
	cout << "Enter the float values"<< endl;
	cin >> c >>d;
	cout<<"for 1st test : "<<Getmax<int>(a,b)<<endl;
	cout<<"for the 2nd test : "<<Getmax<float>(c,d)<<endl;
	return 0;
}
