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

template<class U>
struct entry{
		U key;
		U *next;
};

template<class U>
class hash_table{
		struct entry<U> *hash;
	public:
		hash_table();
		void set(U);
		~hash_table();
};

template<class U>
hash_table<U>::hash_table( )
{
	hash = new(nothrow)struct entry<U>[n];
	for(int i=0;i<5;i++){
		hash[i]->key = hash_fun(i);
		hash[i]->next = NULL;
	}
}

template<class U>
int hash_fun(U a)
{
	return (a%5);
}

template<class U>
void hash_table<U>::set(U a)
{
	int temp_key,t=0;
	temp_key = hash_fun(a);
	struct entry<U>*s = hash;
	for(int i=0;i<5;i++){
		if(s[i]->key==temp_key){
			t=1;
			break;
		}
	}
	
}


int main()
{
	return 0;
}
