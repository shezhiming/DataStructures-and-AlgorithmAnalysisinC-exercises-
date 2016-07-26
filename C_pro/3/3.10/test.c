#include<stdio.h>
#include"./list.c"
//to solve the Josephus question
void Create_node_list( List L,int total );
void Handle_node_list( List L,int d ,int total );

int main(){
    int total = 0,deliver = 0;
    List Node_array = NULL,Node_next = NULL,Node_first = NULL;
    printf( "Please input the total people:\n" );
    scanf( "%d",&total );
    printf( "Please input the interval people:\n" );
    scanf( "%d",&deliver );
    Node_array = MakeEmpty( Node_array );
    Node_array->Element = 1;
    Node_array->Next = Node_array;//the last Node point aim at the first;
    Create_node_list( Node_array,total );
    Handle_node_list( Node_array,deliver,total );

    return 0;
}

void Create_node_list( List L,int total ){
    List next = NULL,Li = L;
    while( Li->Element < total ){
        next = malloc( sizeof( struct Node ) );
        Li->Next = next;
        next->Element = Li->Element + 1;
        next->Next = L;
        Li = next;
    }
}

void Handle_node_list( List L,int d,int total ){
    List Li = L,next = NULL;
    int i = 0;
    if( d == 0 ){
        for( i = 0;i < (total-1);i++ ){
            next = Li;
            Li = Li->Next;
            printf( "it turn to:%d \n",next->Element );
            free( next );
        }
        printf( "the winer is :%d \n",Li->Element );
    }else {
        while( Li->Next != Li ){
            for( i = 0;i < (d-1);i++ ){
                Li = Li->Next;
             }
             next = Li->Next;
             Li->Next = next->Next;
             printf( "it turn to:%d \n",next->Element );
             free( next );
             Li = Li->Next;

         }
         printf( "the winer is :%d \n",Li->Element );

    }
}


