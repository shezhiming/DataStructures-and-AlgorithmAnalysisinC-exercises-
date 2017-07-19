
/*
int Max( int i,int j ){
    return i > j ? i : j;
}
*/


/*this function will check if the num is a prime number*/
int Is_Prime( int num_1 ){
	int i = 0;
	int c = 0;
	for( i = 2;i <= (int)sqrt( num_1 );++i ){
		if( num_1 % i == 0 ){
			++c;
			break; 
		}
	}
	return c;
}

/*this function will return the next Prime number of num*/
int NextPrime( int num ){
	if( num == 2 ){
		num = 3;
	}else{
		while( ++num ){
			if( !Is_Prime(num) ){
				break;
			}
		}
	}
	return num;
}

int Hash( const char *Key,int TableSize ){
	unsigned int HashVal = 0;
	while( *Key != '\0' ){
		HashVal = ( HashVal << 5 ) + *Key++;
	}
	return HashVal % TableSize;
}

