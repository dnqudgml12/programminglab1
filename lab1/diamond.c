#include <stdio.h>


int main(){

    int num =7;



    for(int i=0;i<num;i++){
        for (int j=num-1;i<j;j--){
            printf(" ");
        }
     for(int j=0;j<2*i+1;j++){

        printf("*");

        
    }
 printf("\n");

    }

 //printf( "%c"*(num*2),"*");
//  printf("\n");
    for(int i=0;i<num;i++){

        for (int j=0;j<i+1 ;j++){
            printf(" ");

        }

        for (int j=0;j<2*num-1-(i+1)*2;j++){
            printf("*");
        }

  printf("\n");
    }


}