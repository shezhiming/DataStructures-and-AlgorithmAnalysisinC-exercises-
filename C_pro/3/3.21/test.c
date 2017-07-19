#include<stdio.h>
#include<stdlib.h>
/*to finish a test that make two stack with a array --2016-7-31 */

typedef int Element;


struct stack{
    int Capacity;
    int Lefttop;
    int Righttop;
    Element *Array;
};

struct stack *CreateStack( int MaxElements ){
    struct stack *s;
    s = malloc( sizeof( struct stack ) );
    if( s == NULL ){
        printf( "Out of space!" );
        exit(-1);
    }
    s->Array = malloc( sizeof(Element)*MaxElements );
    if(s->Array = NULL){
         printf( "Out of space!" );
         exit( -1 );
    }
    s->Capacity = MaxElements;
    s->Lefttop = -1;
    s->Righttop = MaxElements+1;
    return s;
}

int IsFull( struct stack *S ){
     return (S->Lefttop +1 ) == S->Righttop;
}

void Left_push( Element E,struct stack *S ){
    if( IsFull( S ) ){
        printf( "the stack is full!!" );
        exit( -1 );
    }
    S->Array[++S->Lefttop] = E;

}

Element Lefttop( struct stack *S ){
    if( S->Lefttop == -1 ){
        printf( "left is a empty stack" );
        exit( -1 );
    }
    return S->Array[S->Lefttop];

}

void Leftpop( struct stack *S ){
    if( S->Lefttop == -1 ){
        printf( "left is a empty stack" );
        exit( -1 );
    }
    S->Lefttop--;
}

int main(){

}
