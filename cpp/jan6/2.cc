/*
 * vector
 * sort in <algorithm>
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> my_arr;
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
	cout<<"The present capacity : "<<my_arr.capacity()<<endl;
	for(it=my_arr.begin();it!=my_arr.end();it++){
		cout<<*it<<endl;
	}
	cout<<endl;
	cout<<"front : "<<my_arr.front()<<" back : "<<my_arr.back()<<endl;
	return 0;
}
