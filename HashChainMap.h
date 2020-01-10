#pragma once
#include "Record.h"


#define TABLE_SIZE	13


inline int transform(char *key) {
	int number=0;
	while (*key)
		number += (128 + *key++);
	return number;
}

inline int HashFunction(char *key) {
	return transform(key) % TABLE_SIZE;
} 
class HashChainMap
{
	Node*	table[TABLE_SIZE];

public:
	HashChainMap (void) { reset(); }
	~HashChainMap(void) { }
	void reset() {
		for ( int i=0 ; i<TABLE_SIZE ; i++ )
			table[i] = NULL;
	}

	void display( ) {
		for( int i=0 ; i<TABLE_SIZE ; i++ ) {
			printf("[%2d] ", i); 
			for( Node *p=table[i] ; p != NULL ; p=p->getLink() )
				printf("%10s", p->getKey());
			printf("\n"); 
		}
	}
		void addRecord ( Node *n ) {
		int hashValue = HashFunction ( n->getKey() );
		for( Node *p=table[hashValue] ; p != NULL ; p=p->getLink() ) {
			if( p->equal(n->getKey()) ) {
				printf("이미 탐색키가 저장되어 있음\n");
				delete n;
				return;
			}
		}
		n->setLink( table[hashValue] );
		table[hashValue] = n;
	}

	void searchRecord( char *key ) {
		int hashValue = HashFunction ( key );
		for( Node *p=table[hashValue] ; p != NULL ; p=p->getLink() ) {
			if( p->equal(key) ) {
				printf("탐색 성공 ");
				p->display();
				return;
			}
		}
		printf("탐색 실패: %s\n", key );
	}
};