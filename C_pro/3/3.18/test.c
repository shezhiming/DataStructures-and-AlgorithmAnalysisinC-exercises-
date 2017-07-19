#include<stdio.h>
#include"stackar.c"
//Check if parenthesis (  ), brackets [  ], and braces {  } are balanced.



void Balance_parenthese( Stack S,char *C ){
    char c;
    while( *C != '\0' ){
        if( *C == '/' && *(C+1) == '*' ){
            Push( *C,S );
            Push( *++C,S );

        }else if( *C == '*' && *(C+1) == '/' ){
            if(IsEmpty(S))        /*栈里无字符*/
                Error("stack is empty.");
            if(Top( S ) == '*'){
                Pop( S );
            }else{
                printf("the '*/' wrong");
                exit(-1);
            }
            if( Top( S ) == '/' ){
                Pop( S );
            }else{
                printf( "the '/*' wrong" );
                exit(-1);
            }
            C = ( C+2 );
            continue;
        }
        if( *C == '(' || *C == '{' || *C == '[' ){
            Push( *C,S );
        }else if( *C == ')' || *C == '}' || *C == ']' ) {
            if(IsEmpty(S))        /*栈里无字符*/
                Error("stack is empty.");
            c = *C;
            if( c == ')' ){
                if( Top( S ) != '(' ){
                    printf( "the '(' is wrong" );
                    exit(-1);
                }
            Pop( S );
            }else if( c == ']' ){
                if( Top( S ) != '[' ){
                    printf( "the '[' is wrong" );
                    exit(-1);
                }
            Pop( S );
            }else if( c == '}' ){
                if( Top( S ) != '{' ){
                    printf( "the '{' is wrong" );
                    exit(-1);
                }
            Pop( S );
            }
        }
        C++;
    }
    printf( "done!\n" );
}

int main(){
    Stack S;
    char array[40] = "Pascal(begin/end,(),[],{})",array_1[40] = "C(/* */,(),{},[])";
    char *C = array,*C_1 = array_1;
    int i = 40;
    S = CreateStack( i );
    Balance_parenthese( S,C );
    Balance_parenthese( S,C_1 );
    return 0;
}
