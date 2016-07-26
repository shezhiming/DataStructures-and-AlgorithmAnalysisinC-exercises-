#include<stdio.h>
#include<stdlib.h>
#include"fatal.h"
#include"list.h"
#include"list.c"
//to exchange the Node of first and last by O(N)
List exchange_fir_las( List L );
int main(){
    List Li_array = NULL;


    return 0;
}

List exchange_fir_las( List L ){
    if( L == NULL ){
        exit( "it is a NULL point" );
    }
    List next = NULL,Li = L,sec = NULL;
    next = Li->Next;
    Li->Next = NULL;
    while( next != NULL ){
        sec = next->Next;
        next->Next = Li;
        Li = next;
        next = sec;

    }
    L = Li;
    return L;
}


