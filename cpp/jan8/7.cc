/*
 * Implementing my_hash;
 *
 */

#include <iostream>
#include <map>

using namespace std;

/*
template<template<class T1, class T2> class T3>       - only one template can be taken this type declaration is not possible

*/
template<class T1, class T2>
class my_hash{
	public:
		map<T1,T2> obj;
		void set(T1 a, T2 b);
};

template<class T1, class T2>
void my_hash<T1,T2>::set(T1 key, T2 val)
{
	obj.insert(key,val);
}

int main()
{
	my_hash<int,int> obj;
	return 0;
}
