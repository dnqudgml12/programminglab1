#include <stdio.h>

int main(){
int size=0;
int starts,blank1,blank2;
// 별의 갯수, 빈칸1의 갯수, 빈칸2의 갯수

printf("input number:");
scanf("%d",&size);
int i,j;

blank1=0;

blank2=2*(size)-2;

for(i=0;i<size;i++){
    for(j=0;j<blank1;j++){
        printf(" ");
    }
    printf("*");
    for(j=0;j<(blank2);j++){
        printf(" ");
    }
    printf("*");
    printf("\n");
    blank1++;
    blank2-=2;
}

starts=2*size;
for(i=0;i<size;i++){
    for(int j=0;j<(starts);j++){
        printf("*");
    }
    printf("\n");
}



blank1=0;

blank2=2*(size)-2;

for(i=0;i<size;i++){
    for(j=0;j<blank1;j++){
        printf(" ");
    }
    printf("*");
    for(j=0;j<(blank2);j++){
        printf("*");
    }
    printf("*");
    printf("\n");
    blank1++;
    blank2-=2;
}

for(i=0;i<starts;i++){
    printf("*");
    
    
}


return 0;
}