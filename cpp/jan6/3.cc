/*
 * vector
 * sort in <algorithm>
 * construct a vector out of another :  construct v1 out of my_arr
 *										assignment
 *										out of the elements of my_arr
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> my_arr;
	vector<int> v1;
	int a;
	vector<int>::iterator it;
	cout<<"The capacity for default constructor : "<<my_arr.capacity()<<endl;
	my_arr.push_back(6);
	cout<<"The present capacity after adding element :"<<my_arr.capacity()<<endl;
	cout<<"The element in my_arr: "<<my_arr[0]<<endl;
	for(int i=0;i<6;i++){
		cin >> a;
		my_arr.push_back(a);
	}
	sort(my_arr.begin(),my_arr.end());
	v1 = my_arr;
	cout<<"The present capacity : "<<my_arr.capacity()<<endl;
	for(it=v1.begin();it!=v1.end();it++){
		cout<<*it<<endl;
	}

	return 0;
}
