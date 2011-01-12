/*
 *using the read and seek functions
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream myfile("eg2.txt");
	char * memblock = new(nothrow)char[10];
	if(myfile.is_open()){
		myfile.seekg(0,ios::beg);
		myfile.read(memblock,10);
		myfile.close();
	}
	cout<<memblock<<endl;
	delete[] memblock;
	return 0;
}
