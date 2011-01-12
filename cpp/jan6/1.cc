/*
 *Find the highest element
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector<int> my_arr;
	cout<<"The capacity for default constructor : "<<my_arr.capacity()<<endl;
	my_arr.push_back(6);
	cout<<"The present capacity after adding element :"<<my_arr.capacity()<<endl;
	cout<<"The element in my_arr: "<<my_arr[0]<<endl;
	return 0;
}
