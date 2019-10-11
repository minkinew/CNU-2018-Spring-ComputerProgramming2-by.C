#include <stdio.h>

count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]); //count_num 함수 

int main(){
	int ary1[3][4] = { // ary1배열 생성 및 초기화
		{ 15, 3, 9, 11 },
		{ 23, 7, 10, 12 },
		{ 0, 17, 55, 24 }
	};
	
	int ary2[3][4] = { //ary2 배열 생성 및 초기화
		{ 13, 8, 9, 15 },
		{ 23, 0, 10, 11 },
		{ 29, 17, 43, 3 }
	};

	int same_num[12][2]; //중복된 행, 열을 저장하는 배열 
	int cnt;
	cnt = count_num(ary1, ary2, same_num); //cnt 정의

	printf("일치하는 번호의 수 : %d\n", cnt);
	printf("배열에서의 위치(행, 열)...\n");

	for (int i = 0; i < cnt; i++){ 
		printf("(%d, %d)\n", same_num[i][0], same_num[i][1]);
	}
	return 0;
}

count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]){ //count_num 함수 정의 
	int count = 0;

	for (int i = 1; i < 4; i++){ //같은 위치에 값이 있을 때 그 갯수를 세어서 배열에 저장하는 반복문
		for (int j = 1; j < 5; j++){
			if (ary1[i-1][j-1] == ary2[i-1][j-1]){ //행, 열의 값이 같을 때
				same_num[count][0] = i-1;
				same_num[count][1] = j-1;
				count++;
			}
		}
	}
	return count;
} //초기화된 2개의 2차원 배열에서 같은 위치에 값이 있는 경우 그수를 세어서 배열에 저장하고 갯수를 반환
