/*
 *factorial for higher values
 */
#include <cstdlib>
#include <iostream>

using namespace std;

double fact(int n)
{
	if(n==0) return 1;
	else return n*fact(n-1);
}

int main()
{
	int n;
	cout << "Enter the number";
	cin >>n;
	if(n<0)
		exit(1);
	cout<<"factorial of "<<n<<" is "<<fact(n)<<endl;
	return 0;
}
