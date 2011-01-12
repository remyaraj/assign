/*
 *sample with excepiton handling
 */
#include <iostream>
#include <exception>

using namespace std;

class myexcep:public exception{
	virtual const char * what() const throw()
	{
		return "Myexception handled";
	}		
};

int main()
{
	myexcep myexc;
	try{
		throw myexc;
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
	return 0;
}
