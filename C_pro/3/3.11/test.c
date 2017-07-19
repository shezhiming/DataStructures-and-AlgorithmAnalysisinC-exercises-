#include<stdio.h>
#include<stdlib.h>
#include"fatal.h"
#include"list.h"
#include"list.c"
void Find_sp_num( List L,int num );
List Find_sp_num_re( List L,int num );

//the program is to find the number that we give  --no recursion

void Find_sp_num( List L,int num ){

}





//the program is to find the number that we give  --no recursion

List Find_sp_num_re( List L,int num ){
    if( L == NULL ){
        error( "it is a NuLL point" );
    }
    if( L->Element != num ){
        if( L->Next == NULL ){
            error( "end list" );
        }
        return Find_sp_num_re( L->Next,num );
    }
    return L;
}
