#pragma once
#include <stdio.h>
#include <string.h>
#define KEY_SIZE		64	// 탐색키의 최대길이
#define VALUE_SIZE		64	// 탐색키와 관련된 정보

class Record {
	char key[KEY_SIZE];		// 키 필드 (사전의 경우 “단어”에 해당)
	char value[VALUE_SIZE];	// 관련된 자료 (사전의 경우 “의미”에 해당)
public:
	Record( char *k="", char*d="" ) { set(k, d); }
	~Record() {}
	void set ( char *k, char*v="" ) {
		strcpy(key, k);
		strcpy(value, v);
	}
	void	reset()		{ set("", ""); }
	char*	getKey()		{ return key; }
	char*	getValue()		{ return value; }
	void	setKey(char *k)	{ strcpy(key, k); }
	bool	isEmpty()		{ return key[0] == '\0'; }
	bool	equal( char *k)	{ return strcmp(k, key)==0; }
	void	display( )		{ printf("%20s = %s\n", key, value); }
};

class Node : public Record
{
	Node*	link;
public:
	Node( char* key, char* val): Record(key, val), link(NULL) { }
	Node* getLink()	 { return link; }
	void setLink(Node* next) { link=next; }
};

