#include <stdlib.h>
#include "HashChainMap.h"

void main()
{
	HashChainMap hash;

	hash.addRecord( new Node("do",	"�ݺ�" ));
	hash.addRecord( new Node("for", "�ݺ�" ));
	hash.addRecord( new Node("if",	"�б�" ));
	hash.addRecord( new Node("case","�б�" ));
	hash.addRecord( new Node("else","�б�" ));
	hash.addRecord( new Node("return",	"��ȯ" ));
	hash.addRecord( new Node("function","�Լ�" ));

	hash.display();
	hash.searchRecord( "case" );
	hash.searchRecord( "function" );
	hash.searchRecord( "class" );
	system("pause");
}