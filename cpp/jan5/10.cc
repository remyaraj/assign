/*
 * vector container: appending values to dynamic arrays and displaying it
 *
 * vector:: iterator declarations
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>	my_vec;
	vector<int>::iterator it;
	vector<int>::iterator temp;

	// for appending values to a dynamic array
	for(int i=0;i<10;i++){
		my_vec.push_back(i);
	}

	// for displaying
	for(it = my_vec.begin();it!=my_vec.end();it++){
		cout << *it << endl;
	}

	cout << "The first element is "<< my_vec.front()<< endl;
	cout << "The last element is "<< my_vec.back()<<endl;

	for(it = my_vec.begin();it!=my_vec.end();it++){
		my_vec.erase(it);
		for(temp = my_vec.begin();)
		cout<<*it<<endl;
	}
	
	return 0;
}
