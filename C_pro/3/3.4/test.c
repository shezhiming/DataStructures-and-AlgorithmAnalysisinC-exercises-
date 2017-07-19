#include<stdio.h>
#include<stdlib.h>
//we will let the L or P on this

void Or_two_list( struct list L,struct list P ){
    struct list l_li = NULL,p_li = NULL,li_array = NULL,next = NULL,before = NULL;
    l_li = L;
    p_li = P;
    li_array = malloc( sizeof(struct List) );
    before = li_array;
    while( l_li != NULL && p_li != NULL ){
        if( l_li->num < p_li->num ){
            l_li = l_li->next;
        }else if( p_li->num < l_li->num ){
            p_li = p_li->next;
        }else {
            next = malloc( sizeof(struct List) );
            next->num = p_li->num;
            next->next = NULL;
            before->next = next;
            before = next;
            l_li = l_li->next;
            p_li = l_li->next;
        }
    }

}


