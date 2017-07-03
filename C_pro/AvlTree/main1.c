#include <stdio.h>
#include <stdlib.h>
#include "../../function.h" 

typedef struct Node *Position;
typedef struct Node *AvlTree;

struct Node{
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

Position SingleRotateWithLeft( Position K2 ){
	printf( "222\n" );
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K1->Height = Max( Height( K1->Left),Height( K1->Right ) ) + 1;
	K2->Height = Max( Height( K2->Left),Height( K2->Right ) ) + 1;
	//printf( "singleleft:%d \n",K2->Element);
	return K1;
}

Position SingleRotateWithRight( Position K2 ){
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K1->Height = Max( Height( K1->Left),Height( K1->Right ) ) + 1;
	K2->Height = Max( Height( K2->Left),Height( K2->Right ) ) + 1;
	//printf( "singleright:%d \n",K2->Element);
	return K1;
}

Position DoubleRotateWithLeft( Position K3 ){
	K3->Left = SingleRotateWithRight( K3->Left );
	return SingleRotateWithLeft( K3 );
}

Position DoubleRotateWithRight( Position K3 ){
	K3->Right = SingleRotateWithLeft( K3->Right );
	return SingleRotateWithRight( K3 );
}

int Height( Position T ){
	if( T == NULL ){
		return -1;
	}else {
		return T->Height;
	}
}

AvlTree MakeEmpty( int X,AvlTree T ){
	if( T == NULL ){
		printf( "it is full!" );
		exit(-1); 
	}
	T->Left = T->Right = NULL;
	T->Height = 0;
	T->Element = X;
	return T;
}

Position Find( int X,AvlTree T){
	if( T == NULL ){
		exit( -1 );
	}else if( X < T->Element ){
		return Find( X,T->Left );
	}else if( X > T->Element ){
		return Find( X,T->Right );
	}else{
		return T;
	}
}

AvlTree Insert( int X,AvlTree T ){
	if( T == NULL ){
		T = malloc( sizeof( struct Node ) );
		if( T == NULL ){
			printf( "it is full!" );
			exit(-1);
		}
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}else if( X < T->Element ){
		T->Left = Insert( X,T->Left );
		if( Height( T->Left ) - Height( T->Right ) == 2 ){
			if( X < T->Left->Element ){
				T = SingleRotateWithLeft( T );
			}else{
				T = DoubleRotateWithLeft( T );
			}
		}
	}else if( X > T->Element ){
		T->Right = Insert( X,T->Right );
		if( Height( T->Right ) - Height( T->Left ) == 2 ){
			if( X > T->Right->Element ){
				T = SingleRotateWithRight( T );
			}else{
				T = DoubleRotateWithRight( T );
			}
		}
	}
	T->Height = Max( Height( T->Left ),Height( T->Right ) ) + 1;
	return T;
}

void PrintTree( AvlTree T ){
	if( T != NULL ){
		PrintTree( T->Left );
		printf( "%d \n",T->Element );
		PrintTree( T->Right );
	}
}

Position FindMax( AvlTree T){
	if( T == NULL ){
		return NULL;
	}else if( T->Right == NULL ){
		return T;
	}else{
	return FindMax( T->Right );
	}
}

Position FindMin( AvlTree T ){
	if( T == NULL ){
		return NULL;
	}else if( T->Left == NULL ){
		return T;
	}else{
		return FindMin( T->Left );
	}
}
AvlTree Delete( int X,AvlTree T ){
	Position TmpCell;
	if( T == NULL){
		printf( "it's not have the element'!" );
		exit(-1);
	}
	if( X < T->Element ){
		T->Left = Delete( X,T->Left );
	}else if ( X > T->Element ){
		T->Right = Delete( X,T->Right );
	}else{
		//it have the left tree and the right tree
		if( T->Left && T->Right ){
			T->Element = FindMin( T->Right )->Element;
			Delete( T->Element,T->Right );
		}else{
			TmpCell = T;
			if( (T->Left == NULL) && (T->Right == NULL) ){
				free( T );
				return NULL;
			}else if( T->Left == NULL ){
				T = T->Right;
			}else if( T->Right == NULL ){
				T = T->Left;
			}
			free( TmpCell );
			/*if T just have one or zero child,it should count it's Height,
			so we should return T at the block*/
		}
	}
	T->Height = Max( Height( T->Left ),Height( T->Right ) ) + 1;
	//printf( "the delete turn elementis %d",T->Element );
	/*delete the element,then we will check the tree is AvlTree*/
	if( Height( T->Left ) - Height( T->Right ) == 2 ){
		if( T->Left->Left ){
			T = SingleRotateWithLeft( T );
		}else{
			T = DoubleRotateWithLeft( T );
		}
	}else if( Height( T->Right ) - Height( T->Left ) == 2 ){
		if( T->Right->Right ){
			T = SingleRotateWithRight( T );
		}else{
			T = DoubleRotateWithRight( T );
		}
	}
	return T;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Position SingleRotateWithLeft( Position K2 );
	Position SingleRotateWithRight( Position K2 );
	Position DoubleRotateWithLeft( Position K3 );
	Position DoubleRotateWithRight( Position K3 );
	int Height( Position P );
	AvlTree MakeEmpty( int X,AvlTree T );
	Position Find( int X,AvlTree T );
	Position FindMin( AvlTree T );
	Position FindMax( AvlTree T );
	AvlTree Insert( int X,AvlTree T );
	AvlTree Delete( int X,AvlTree T );
	void PrintTree( AvlTree T );
	
	Position T = malloc( sizeof( struct Node ) );
	int i = 0;
	MakeEmpty( 10,T );
	while( scanf( "%d",&i ) != EOF ){
		T = Insert( i,T );
		PrintTree( T );
		printf( "!-------------------------------" );
	}
	while( scanf( "%d",&i ) != EOF ){
		T = Delete( i,T );
		PrintTree( T );
		printf( "!-------------------------------" );
	}
	return 0;
}
