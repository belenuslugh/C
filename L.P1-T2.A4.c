#include <stdio.h>
#include <math.h>

int Ackerman( int m , int n);

int main()
{
	int  m , n;

    do{
		printf("Ackerman m e n? \n");
		scanf(" %d %d",&m,&n);
		
		if(m != 0 || n != 0){
    	    printf("Ackerman: %d\n", Ackerman(m,n));
		}
	}while(m != 0 || n != 0);
	return 0;
}

int Ackerman( int m , int n){
    if (m == 0 ){
        return   n+1;
    }else if( n == 0){
        return  Ackerman(m-1, 1);
    }else {
        return  Ackerman(m-1,Ackerman(m,n-1));
    }
}
