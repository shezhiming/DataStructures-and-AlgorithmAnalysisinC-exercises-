#include <stdio.h>
#include <stdlib.h>
#include"../fatal.h"  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insertionSort(int Array[],int N){
	int i = 0,j = 0;
	int tem = 0;
	for( i = 1;i < N;i++ ){
		tem = Array[i];
		
		for( j = i;j > 0 && tem < Array[j-1];j-- ){
			Array[j] = Array[j-1];
		}
		
		Array[j] = tem;
	}
	
	for( i = 0;i < 9;i++ ){
		printf("%d",Array[i]);
	}
	
}

int main(int argc, char *argv[]) {
	int A[9] = {3,1,4,1,5,9,2,6,5};
	int i = 0; 
	insertionSort(A,9);
	
	return 0;
}
