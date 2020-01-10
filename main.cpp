#include <stdlib.h>
#include "HashChainMap.h"

void main()
{
	HashChainMap hash;

	hash.addRecord( new Node("do",	"반복" ));
	hash.addRecord( new Node("for", "반복" ));
	hash.addRecord( new Node("if",	"분기" ));
	hash.addRecord( new Node("case","분기" ));
	hash.addRecord( new Node("else","분기" ));
	hash.addRecord( new Node("return",	"반환" ));
	hash.addRecord( new Node("function","함수" ));

	hash.display();
	hash.searchRecord( "case" );
	hash.searchRecord( "function" );
	hash.searchRecord( "class" );
	system("pause");
}