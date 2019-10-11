#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void makeLottoNumber(int *lottoNums); //makeLottoNumber 함수 선언
void sortArray(int *lottoNums); //sortArray 함수 선언
void swap(int *x, int*y); //swap 함수 선언
int checkLottoNumber(int *lottoNums); //checkLottoNumber 함수 선언

int main(){
	int lottoNums[6]; //배열 선언
	
	makeLottoNumber(lottoNums); //makeLottoNumber 함수 호출

	checkLottoNumber(lottoNums); //checkLottoNumber 함수 호출
}
void makeLottoNumber(int *lottoNums){ //makeLottoNumber 함수 정의
	int m; //변수 선언

	srand((unsigned)time(NULL));  //srand 함수

	for (int i = 0; i < 6; i++){ //중복을 제거한 랜덤값 배열 저장
	again:;
		m = rand() % 45 + 1;
		for (int j = 0; j < i - 1; j++)
		if (m == lottoNums[j])
			goto again; // 중복 숫자 발견 시 again:으로 돌아감
				lottoNums[i] = m;	
		}
	sortArray(lottoNums); //sortArray 함수 호출
	}


void sortArray(int *lottoNums){  //sortArray 함수 정의
	for (int i = 0; i < 6; i++){
		int *k = lottoNums + i;  //포인터 k에 최솟값 저장
		for (int j = i; j < 6; j++){ //배열을 순차적으로 탐색해서 값을 비교하여 swap함수를 통해 자리를 바꿔줌
			if (*(lottoNums + j) < *k)
				k = lottoNums + j;
			swap(k, lottoNums + i);  //swqp함수 호출
		}
	}
}

void swap(int *x, int*y){ //swap함수 정의
	int z = *x; //교환을 위한 변수 z에 x값 저장
	*x = *y; //x에 y값 저장
	*y = z; // y에 z값 저장
}

int checkLottoNumber(int *lottoNums){ //checkLottoNumber 함수 정의
	int lottoA[6]; //배열 A 선언
	int lottoB[6]; //배열 B 선언
	int count = 0; //count 변수 선언

	for (int i = 0; i < 6; i++){ //배열 A를 배열 B에 저장 후 중복 숫자 비교확인
		printf("번호 입력 : \n");
		scanf("%d", &lottoA[i]);
		lottoB[i] = lottoA[i];

		if (lottoA[i] > 0 && lottoA[i] <= 45){ //배열 A의 값이 1~45의 숫자 일 때
			for (int j = 0; j < i; j++){
				if (lottoB[j] == lottoA[i]){ //배열 B와 배열 A의 값이 같을 때
					printf("같은 번호가 있습니다.\n");
					i--;
					break;
				}
			}
		}
		else { //1~45의 숫자가 아닐 때
			printf("1부터 45까지의 수만 입력하세요.\n");
			i--;
		}
		for (int j = 0; j < 6; j++) //배열 A의 값과 로또번호 값을 비교해서 몇개가 같은지 확인
			if (lottoA[i] == lottoNums[j] )
				count ++;
	}
	for (int i = 0; i < 6; i++){ //로또번호 랜덤 생성
		printf("%3d", lottoNums[i]);
	}
	printf("\n");
	printf("총 %d개의 맞는 숫자가 있습니다.\n", count); 
}
