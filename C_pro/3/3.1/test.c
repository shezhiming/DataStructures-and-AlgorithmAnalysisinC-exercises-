#include<stdio.h>
#include<stdlib.h>
//printf the list of the single list;


struct list{
    struct list *next;
    int num;

};
int main(){
    int i = 0;
    struct list *li = NULL,*next = NULL,*first = NULL;
    first = malloc( sizeof( struct list  )  );
    next = first;//create the list firt
    for(i = 0;i < 10;i++){
        li = malloc( sizeof( struct list  )  );
        li->num = i;
        next->next = li;
        next = li;
    }
    next->next = NULL;
    next = first->next;
    while( next != NULL ){
        printf( "%d\n",next->num );
        next = next->next;
    }
    return 0;

}
