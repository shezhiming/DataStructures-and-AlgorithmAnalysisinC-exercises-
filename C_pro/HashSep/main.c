#include <stdio.h>
#include <stdlib.h>
#include "../../function.h"
#include <math.h> 

/**
 *　　　　　　　　�芥掘　　？芥�+ +
 *　　　　　　　�芥食潯ォォォ食潯� + +
 *　　　　　　　�А　　　　　　？� 　
 *　　　　　　　�А　　？ァ　　？� ++ + + +
 *　　　　　　 ���������エ������� ��+
 *　　　　　　　�А　　　　　　？� +
 *　　　　　　　�А　　？漾　　？�
 *　　　　　　　�А　　　　　　？� + +
 *　　　　　　　�皐ォ掘　　？芥ォ�
 *　　　　　　　　　�А　　？А　　　　　　　　　　�
 *　　　　　　　　　�А　　？� + + + +
 *　　　　　　　　　�А　　？А　　　�Code is far away from bug with the animal protecting　　　　　　　
 *　　　　　　　　　�А　　？� + 　　　　舞舗隠嗷,旗鷹涙bug　　
 *　　　　　　　　　�А　　？�
 *　　　　　　　　　�А　　？А　�+　　　　　　　　　
 *　　　　　　　　　�А� 　　�皐ォォォ� + +
 *　　　　　　　　　�� 　　　　　　　�禰�
 *　　　　　　　　　�� 　　　　　　　�芥�
 *　　　　　　　　　�皐粂粂芥ォ廩粂芥� + + + +
 *　　　　　　　　　　�З路蓮？З路�
 *　　　　　　　　　　�皐潯拭？皐潯�+ + + +
 */
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct ListNode *Position;
typedef struct HashTbl *HashTable;

struct ListNode{
	char *Element;
	Position Next;
};

typedef Position List;

struct HashTbl{
	int TableSize;
	List *TheLists;
};

HashTable InitializTable( int TableSize ){
	HashTable H;
	int i;
	H = malloc( sizeof( struct HashTbl ) );
	if( H == NULL ){
		printf( "Out of space" );
		exit( -1 );
	}
	H->TableSize = NextPrime( TableSize );
	printf( "%d\n",H->TableSize );
	H->TheLists = malloc( sizeof( struct HashTbl ) * TableSize );
	if( H->TheLists == NULL ){
		printf( "Out of space" );
		exit( -1 );
	}
	for( i = 0;i < H->TableSize;i++ ){
		H->TheLists[i] = malloc( sizeof( struct ListNode ) );
		if( H->TheLists[i] == NULL ){
			printf( "Out of space" );
			exit( -1 );
		}else{
			H->TheLists[i] = NULL;
		}
	}
	return H;
}
Position Find( char *Key,HashTable H ){
	Position P;
	List L;
	L = H->TheLists[ Hash( Key,H->TableSize ) ];
	P = L->Next;
	while( P != NULL && P->Element != Key ){
		P = P->Next;
	}
	return P;
}

void Insert( char *Key,HashTable H ){
	Position Pos,NewCell;
	List L;
	Pos = Find( Key,H );
	if( Pos == NULL ){
		NewCell = malloc( sizeof( struct ListNode ) );
		if( NewCell == NULL ){
			printf( "Out of space!" );
		}
		L = Hash( Key,H->TableSize );
		NewCell->Element = Key;
		NewCell->Next = L->Next;
		L->Next = NewCell;
	}
}

int main(int argc, char *argv[]) {
	HashTable InitializTable( int TableSize );
	void DestroyTable( HashTable H );
	Position Find( char *Key,HashTable H );
	void Insert( char *Key,HashTable H );
	int Reterieve( Position P );
	char a[10];
	char *b = a;
	int i = 0;

	return 0;
}
