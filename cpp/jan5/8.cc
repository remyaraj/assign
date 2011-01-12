/*
 *dynamic_cast only for derived to base not base to derived unless its polymorphic
 */


#include <iostream>
#include <new>
#include <exception>
using namespace std;

class polygon{
	protected:
		int height, width;
};

class rect:public polygon{
	public:
		int area(){return(height * width);}
};

int main()
{
	polygon *poly;
	rect *rec;
	try{
	poly = dynamic_cast<rect*>(new polygon);
	if(poly == NULL)
		cout<<"No pointer allocated"<<endl;
	else
		cout<<"pointer allocated for base to derived"<<endl;
	}
	catch(exception& e){
		cout<< "Exception arised"<<endl;
	}
	try{
	rec = dynamic_cast<polygon*>(new rect);
	if(rec==NULL)
		cout<<"No pointer allocated for derived to base class"<<endl;
	else
		cout<<"Pointer allocation success for derived to base class"<<endl;
	}
	catch(exception& e){
		cout<<"Exception arised"<<endl;
	}

	delete poly;
	delete rec;
	return 0;
}
