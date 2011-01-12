/*
 *map insertion
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	char a;
	int b;
	map<char,int> m1;
	map<char,int>::iterator it;
	for(int i=0;i<5;i++){
		cout<<"char int"<<endl;
		cin>>a>>b;
		m1.insert(pair<char, int>(a,b));
	}

	for(it=m1.begin();it!=m1.end();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
	return 0;
}
