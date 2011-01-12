/*
 * good() : returns false if eof is reached else if error occured
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream myfile("eg2.txt");
	string mystr;
	if(myfile.is_open()){
		myfile<<"hai dears\n";
		getline(cin,mystr);
		myfile<<mystr;
		myfile.close();
	}
	ifstream myfile1("eg2.txt");
	if(myfile1.is_open()){
		while(myfile1.good()){
			getline(myfile1,mystr);
			cout<<mystr<<endl;
			cout<<"..................."<<endl;
		}
	}

	return 0;
}
