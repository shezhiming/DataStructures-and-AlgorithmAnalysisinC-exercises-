#include<stdio.h>
#include<stdlib.h>
//the single list change num by point

struct list *chang_single_list( List L ){
    struct list L_fir = NULL,L_sec = NULL;
    L_fir = L->next;
    L_sec = L_fir->next;
    L->next = L_sec;
    L_fir->next = L_sec->next;
    L_sec->next = L_fir;
    return L;
}


struct list *chang_single_list( List L ){
    struct list L_fir = NULL,L_sec = NULL;
    L_fir = L->next;
    L_sec = L_fir->next;

    L->next = L_sec;
    L_fir->next = L_sec->next;
    L_fir->before = L_sec;
    L_sec->before = L;
    L_sec->next = L_fir;
    return L;

}
