#include<stdio.h>
#include<stdlib.h>
//to print the L list element by P element

PrintLost(L,P){
    int p_num = 0,i = 0;
    struct list *p_next = NULL,l_next = NULL;
    l_next = L;
    p_next = P;
    while( p_next->next != NULL ){
        while( i != p_next->num || l_next-> null != NULL ){
            i++;
            l_next = l_next->next;
        }
        if(l_next == NULL ){
             printf("the L list is over!");
             break;
        }
        printf(" %d/n",l_next->num );
        p_next = p_next->next;
    }
    return 0;
}
