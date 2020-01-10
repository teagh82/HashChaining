#pragma once
#include <stdio.h>
#include <string.h>
#define KEY_SIZE		64	// Ž��Ű�� �ִ����
#define VALUE_SIZE		64	// Ž��Ű�� ���õ� ����

class Record {
	char key[KEY_SIZE];		// Ű �ʵ� (������ ��� ���ܾ�� �ش�)
	char value[VALUE_SIZE];	// ���õ� �ڷ� (������ ��� ���ǹ̡��� �ش�)
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

