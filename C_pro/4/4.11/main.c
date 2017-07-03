#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*实现二叉查找树*/ 
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T ){
	if( T != NULL ){
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
	}
	return NULL;
}

Position Find( int X,SearchTree T ){
	if( T == NULL ){
		return NULL;
	}else if( X < T->Element ){
		Find( X,T->Left );
	}else if( X > T->Element ){
		Find( X,T->Right );
	}else{
		return T;
	}
}

Position FindMin( SearchTree T ){
	if( T == NULL ){
		return NULL;
	}else if( T->Left == NULL ){
		return T;
	}else{
		return FindMin( T->Left );
	}
}

Position FindMax( SearchTree T ){
	if( T == NULL ){
		return NULL;
	}else if( T->Right == NULL ){
		return T;
	}else{
		return FindMax( T->Right );
	}
}

SearchTree Insert( int X,SearchTree T ){
	if( T == NULL ){
		T = (SearchTree)malloc( sizeof(struct TreeNode ) );
		T->Element = X;
		T->Left = T->Right = NULL;
	}else if( X < T->Element ){
		T->Left = Insert( X,T->Left );
	}else if( X > T->Element ){
		T->Right = Insert( X,T->Right );
	}
	return T;
}

SearchTree Delete( int X,SearchTree T ){
	SearchTree Del,Replace;
	Del = Find( X,T );
	if( Del == NULL ){
		return NULL;
	}else if( Del->Left == NULL && Del->Right == NULL ){
		free( Del );
	}else if( Del->Left || Del->Right ){
		if( Del->Left ){
			Del->Element = Del->Left->Element;
			free( Del->Left );
		}else{
			Del->Element = Del->Right->Element;
			free( Del->Right );
		}
	}else{
		Replace = FindMin( Del->Right );
		Del->Element = Replace->Element;
		Delete( Del->Element,Del->Right );
	}
}

int main(int argc, char *argv[] ) {
	SearchTree MakeEmpty( SearchTree T );
	Position Find( int X,SearchTree T );
	Position FindMin( SearchTree T );
	Position FindMax( SearchTree T );
	SearchTree Insert( int X,SearchTree T );
	SearchTree Delete( int X,SearchTree T );
	int Retrieve( Position P );
	
	return 0;
}
