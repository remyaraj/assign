/*
 *map key-value pair
 *
 * a key has only single value.. it gets overwritten if again assigned for the same key
 *
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string,int> m1;
	map<string,int>::iterator it;
	m1["A"] = 7;
	m1["K"] = 1;
	m1["A"] = 15;
	for(it=m1.begin();it!=m1.end();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
	return 0;
}
