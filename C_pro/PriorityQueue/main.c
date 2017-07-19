#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct HeapStruct{
	int Capacity;
	int Size;
	int *Element;
};

typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize( int MaxElements ){
	PriorityQueue H;
	int i = 0;
	H = malloc( sizeof( struct HeapStruct ) );
	if( H == NULL ){
		printf( "Out of space!" );
		exit( -1 );
	}
	H->Element = malloc( sizeof(int) * ( MaxElements + 1 ) );
	if( H->Element == NULL ){
		printf( "Out of space!" );
		exit( -1 );
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Element[0] = '\0';
	return H;
}

int IsFull( PriorityQueue H ){
	if( (H->Size+1) >= H->Capacity ){
		return 1;
		//full the Queue
	}
	return 0;
}

int IsEmpty( PriorityQueue H ){
	if( H->Size == 0 ){
		return 1;
	}
	return 0;
}

void Insert( int X,PriorityQueue H ){
	int i = 0;
	if( IsFull( H ) ){
		printf( "Full of Queue!" );
		exit( -1 );
	}
	//printf( "%d",H->Size );
	if( H->Size != 0 ){
		for( i = ++H->Size;H->Element[ i/2 ] > X;i /= 2 ){
			H->Element[ i ] = H->Element[ i/2 ];
		}
		H->Element[ i ] = X;
	}else {
		H->Element[ ++H->Size ] = X;
	}
	printf( "insert index:%d\n",i );
	printf( "insert number:%d\n",H->Element[ i ] );
}

int DeleteMin( PriorityQueue H ){
	if( IsEmpty( H ) ){
		printf( "It's empty!" );
		exit( -1 );
	}
	int i = 0;
	int Element = 0,LastElement = 0;
	Element = H->Element[ 1 ];
	//printf( "%d\n",Element );
	//exit( 1 );
	LastElement = H->Element[ H->Size-- ];
	printf( "Size is %d\n\n",H->Size );
	printf( "j is %d\n\n",LastElement );
	for( i = 1;i <= H->Size;i *= 2 ){
		if( i != H->Size && ( H->Element[ i ] > H->Element[ i + 1 ] ) ){
			i++;
		}
		//H->Element[ i/2 ] = H->Element[ i ];
		if( LastElement > H->Element[ i ] ){
			H->Element[ i/2 ] = H->Element[ i ];
		}else{
			break;
		}
		
	}
	i /= 2;
	H->Element[ i ] = LastElement;
	printf( "Delete number:%d\n",Element );
	return Element;
}
int main(int argc, char *argv[]) {
	PriorityQueue Initialize( int MaxElements );
	void Destroy( PriorityQueue H );
	void MakeEmpty( PriorityQueue H );
	void Insert( int X,PriorityQueue H );
	int DeleteMin( PriorityQueue H );
	int FindMin( PriorityQueue H );
	int IsEmpty( PriorityQueue H );
	int IsFull( PriorityQueue H );
	int i = 0,j = 0;
	PriorityQueue H;
	scanf( "%d",&i );
	H = Initialize( i );
	//printf( "%d",H->Size );
	printf( "Please input the Queue number!\n" );
	//while( scanf( "%d",&i ) ){
	//	Insert( i,H );
	//}
	for( j = 0;j < 12;++j ){
		scanf( "%d",&i );
		Insert( i,H );
	}
	printf( "!----------------------\n" );
	for( j = 0;j < 13;++j ){
		printf( "%d",H->Element[j]);
	}
	printf( "!----------------------\n" );
	while( 1 ){
		i = DeleteMin( H );
		//printf( "%d\n",i );
	}
	return 0;
}

/*
for( i = 1;i * 2 <= H->Size;i = Child ){
		Child = i * 2;
		if( Child != H->Size && ( H->Element[ Child ] > H->Element[ Child + 1 ] ) ){
			Child += 1;
		}
		
		if( LastElement > H->Element[ Child ] ){
			H->Element[ i ] = H->Element[ Child ];
		}else{
			break;
		}
*/
