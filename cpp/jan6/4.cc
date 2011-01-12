/*
 *swap and operator==
 * empty,pop_back()
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1(3,10);
	vector<int> v2(3,15);
	vector<int> v3(v1);
	vector<int>::iterator it;
	cout<< "The vectors v1 and v2 are equal : "<<(v1==v2)<<endl;
	cout<< "The vectors v1 and v3 are equal : "<<(v1==v3)<<endl;
	v1.swap(v2);
	for(it = v1.begin();it!=v1.end();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
	while(!v1.empty()){
		v1.pop_back();
	}
	cout<<"The size of v1 is : "<<v1.size()<<endl;
	cout<<"The capacity of vector : "<<v1.capacity()<<endl;

	v1.erase(v1.begin(),v1.end());
	cout<<"The capacity of vector is : "<<v1.capacity()<<endl;
	return 0;
}
