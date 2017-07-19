#include<stdio.h>
#include<stdlib.h>
//L U P ,we will du this

void and_with_two_list(struct list L,struct list P){
    struct list p_li = NULL,l_li = NULL,li_array = NULL,li_next = NULL,li_before = NULL;
    p_li = P;
    l_li = L;
    li_array = malloc( sizeof(struct list) );
    li_array = li_before;
    while( 1 ){
        if( l_li->num < p_li->num ){
            li_next = malloc( sizeof(struct list) );
            li_next->num = l_li->num;
            li_next->next = NULL;
            li_before->next = li_next;
            li_before = li_next;
            l_li = l_li->next;
        }else if(p_li < l_li ){
            li_next = malloc( sizeof(struct list) );
            li_next->num = p_li->num;
            li_next->next = NULL;
            li_before->next = li_next;
            li_before = li_next;
            p_li = p_li->next;
        }else{
            li_next = malloc( sizeof(struct list) );
            li_next->num = p_li->num;
            li_next->next = NULL;
            li_before->next = li_next;
            li_before = li_next;
            p_li = p_li->next;
            l_li = l_li->next;
        }
        if( p_li = NULL ){
            li_before->next = l_li;
            break;
        }else{
            li_before->next = p_li;
            break;
        }

    }


}



