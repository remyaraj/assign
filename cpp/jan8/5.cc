/*
 * map insertion using templates
 * 
 * insertion
 *
 * Not complete
 *
 */
#include <iostream>
#include <new>

using namespace std;

template<class T,class U>
struct entry{
		T key;
		U value;
};

template<class T, class U>
class hash_table{
		struct entry<T,U> **hash;
		int max_size;
		int size ;
	public:
		hash_table(int);
		void insert(T,U);
		~hash_table();
};

template<class T, class U>
hash_table<T,U>::hash_table(int n)
{
	max_size = n;
	size = 0;
	hash = new(nothrow)struct entry<T,U>*[n];
	for(int i=0;i<max_size;i++){
		hash[i] = 0;
	}
}

template<class T,class U>
void hash_table<T,U>::insert(T a, U b)
{
	struct entry<T,U> **s = hash;
	int t=0;
	for(int i=0;i<max_size;i++){
		if(strcmp(s[i],a)==0){
			t=1;
			break;
		}
	}
	if(t==0){
		s[size] = new(nothrow)struct entry<T,U>;
		s[size]->key = a;
		s[size]->value = b;
		size++;
	}
	else{
		cout<<"The key already exist"<<endl;
	}
}

template<class T, class U>
hash_table<T,U>::~hash_table()
{
	struct entry<T,U> **e = hash;
	for(int i=0;i<max_size;i++){
		delete e[i];
	}
	delete []e;
}

int main()
{
	return 0;
}
