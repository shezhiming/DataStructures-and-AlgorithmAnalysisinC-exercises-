#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct StackRecord *Stack;
struct StackRecord {
	int Capacity;
	int Top;
	int *Array;
};

Stack CreatStack( int MaxElement){
	Stack S;
	S = malloc (sizeof( struct StackRecord ) );
	if( S == NULL ){
		exit(-1);
	}
	S->Array = malloc( sizeof( int ) * MaxElement );
	if( S->Array == NULL ){
		exit(-1);
	}
	S->Capacity = MaxElement;
	return S;
}
int main(int argc, char *argv[]) {
	//the function list of stackrecord
	int Isempty( Stack S );
	int IsFull( Stack S );
	Stack CreatStack( int MaxElement);
	void Push( int X,Stack S );
	void DisposeStack( Stack S );
	int Pop( Stack S );
	return 0;
}
