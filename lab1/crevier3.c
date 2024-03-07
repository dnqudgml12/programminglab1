/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
//입력되는 parameter는 array의 row값을 나타낸다.
//방이 5개 이므로 5번 시도
//랜덤값 설정 및 반복문에서 랜덤값의 중복 방지 및 인덱스에 2명이상이 들어갔는지 확인 필요
//2명 이상 들어가지 않도록 설정 되어있음

for(int i=0;i<5;i++){
    int random=(rand()%5+1);
    if(persons[random-1]<2){
        persons[random-1]+=1;
        return random;
    }
}

//랜덤으로 시도 하기에 5번 시도 후에도 방이 발견되지 않는다면 모든 방을 체크.
for(int j = 0; j < 5; j++){
        if(persons[j] < 2){
            persons[j]++;
            return j + 1;
        }
    }
return -1;




}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    // 이 곳에 생각 정리와 코드 구현


    //명단별 호실 목록인 mr, 명단인 mn이용 
   printf("남학생 명단 (%d명)\n",mc);
   for(int i=0;i<mc;i++){
    printf("%d. %s [%d호]\n",i+1,mn[i],mr[i]);
   }

    printf("여학생 명단 (%d명)\n",wc);
   for(int i=0;i<wc;i++){
    printf("%d. %s [%d호]\n",i+1,wn[i],wr[i]);
   }

   // 호실별로 출력 후 호실별 명단인 mn을 통해 명단 출력
   // 출력시에 조건문을 넣은 것은 명단별 방 배정 목록인 mr과 출력되는 값이 같도록 하기 위해서
   // 조건문이 없으면 분별이 안되서 모든 명단에 다 기록이 된다.
   printf("호실별 배정 명단\n");
   for(int i=0;i<5;i++){
    printf("%d호: ",100+i+1);
    for(int j=0;j<mc;j++){
        if(mr[j]==100+i+1){
            printf("%s ",mn[j]);
        
    }
    printf("\n");

   }

    for(int i=0;i<5;i++){
    printf("%d호: ",200+i+1);
    for(int j=0;j<wc;j++){
        if(wr[j]==200+i+1){
            printf("%s ",wn[j]);
        }
    }
        printf("\n");

   }
   
}
}