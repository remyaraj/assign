/*
 * Generic hashtable using templates
 * 
 * step 1 ; trying out the map 
 *
 * problem : strings wont be sorted as uppercase and lowercase gets mixed up
 *
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string,int> m1;
	map<string,int>::iterator it;
	m1["mydear"] =4;
	m1["gutter"] =8;
	m1["Junk"] = 9;
	m1["ananth"] = 7;
	for(it = m1.begin();it!=m1.end();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
	return 0;
}
