#include<stdio.h>
int main(){
int person[4][3]; // 4개 층별 3개 호실의 점호 인원 수
int sum[3]={0,0,0};// 점호 인원 수 합계 (남, 여, 전체) 
float ratio[3];// 점호 인원 수 비율 (남, 여, 전체)
int i, j;// 반복문을 위한 변수

printf("남학생층 점호 \n");
for(i=0;i<2;i++){
    for(j=0;j<3;j++){
        printf("%d0%d ",i+1,j+1);
        scanf("%d",&person[i][j]);
    }

}
printf("여학생층 점호\n");
for(i=2;i<4;i++){
    for(j=0;j<3;j++){
        printf("%d0%d ",i+1,j+1);
        scanf("%d",&person[i][j]);
    }

}

//남학생 점호 인원 총 수
for(i=0;i<2;i++){
    for(j=0;j<3;j++){
        sum[0]+=person[i][j];
    }

}

//여학생 점호 인원 총수
for(i=2;i<4;i++){
    for(j=0;j<3;j++){
        sum[1]+=person[i][j];
    }

}

//총 학생 점호 인원수
for(i=0;i<4;i++){
    for(j=0;j<3;j++){
        sum[2]+=person[i][j];
    }

}
printf("%d\n",sum[0]);

printf("%d\n",sum[1]);

printf("%d\n",sum[2]);
ratio[0]= 100.0*sum[0]/24;

ratio[1]= 100.0*sum[1]/24;

ratio[2]= 100.0*sum[2]/48;



printf("Check room(Men)\n");
for(i=0;i<2;i++){
    for(j=0;j<3;j++){
        printf("Room #%d0%d > %d",i+1,j+1,person[i][j]);
        printf("\n");
    }

}

printf("Check room(Women)\n");
for(i=2;i<4;i++){
    for(j=0;j<3;j++){
        printf("Room #%d0%d > %d",i+1,j+1,person[i][j]);
        printf("\n");
    }

}
printf("Check Result\n");

printf("Men: %d/%d (%0.1f) %%\n",sum[0],24,ratio[0]);
printf("Women: %d/%d (%0.1f) %%\n",sum[1],24,ratio[1]);
printf("Total: %d/%d (%0.1f) %%\n",sum[2],48,ratio[2]);





return 0;

}