#include<stdio.h>
#include"stackar.c"

void Postfix_expression( char *C,Stack S ){
    char *exp = C,symbol;
    int num_1 = 0,num_2 = 0;
    while( *exp != '\0' ){
        if( *exp >= 48 && *exp <= 57 ){
            Push( ((int)*exp - 48),S );
        }else {
            num_1 = Top( S );
            Pop( S );
            num_2 = Top( S );
            Pop( S );
            switch( *exp ){
                case '+':
                    num_1 = num_1 + num_2;
                    Push( num_1,S );
                    break;
                case '*':
                    num_1 = num_1 * num_2;
                    Push( num_1,S );
                    break;
                case '-':
                    num_1 = num_1 - num_2;
                    Push( num_1,S );
                    break;
                case '/':
                    num_1 = num_1 / num_2;
                    Push( num_1,S );
                    break;
            }
        }
        exp++;
    }
    printf( "%d\n",Top( S ) );
}

int main(){
    char array[20] = "6523+8*+3+*";
    Stack S;
    int i = 40;
    S = CreateStack( i );
    Postfix_expression( array,S );
    return 0;
}
