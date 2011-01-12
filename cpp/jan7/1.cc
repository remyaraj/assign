/*
 * The file operations :
 *
 * ios::app for appendind to the already existing contents
 *
 *ofstream - for writing to file, ifsteam for reading from file
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("eg.txt");
	if(myfile.is_open()){
		myfile<<"writing this to myfile";
	}
	myfile.close();
	myfile.open("eg.txt",ios::app);
	if(myfile.is_open()){
		myfile<<"mydear\n";
	}
	myfile.close();
	return 0;
}
