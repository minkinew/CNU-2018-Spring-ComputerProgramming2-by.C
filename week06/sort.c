#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int*y); //swap함수 생성

void sortArray(int *intArray, int inputSize); //sortArray 함수 생성

int main(){
	int arr[20]; //크기가 20인 배열 지정
	int arraySize; //1~20 사이에서 사용할 배열 선언 변수

	srand((unsigned int)time((time_t*)NULL)); //seed value(랜덤값)

	printf("숫자를 입력하시오. : "); //출력구문
	scanf_s("%d", &arraySize); //사용할 배열 입력 구문
	makeArray(arr, arraySize); //배열 생성

	for (int i = 0; i < arraySize; i++) { //for문을 이용해 배열을 반복생성
		printf("%d\n", arr[i]);
	}

	sortArray(arr, arraySize); //sortArray함수 호출
	printf("변화된 값 : \n");
	
	for (int i = 0; i < arraySize; i++){ //변화된 배열을 for문을 이용해 반복생성
		printf("%d\n", arr[i]);
	}

	return 0;
}


int makeArray(int *intArray, int arraySize){ //1~1000까지의 숫자중에서 랜덤하게 배열에 삽입
	for (int i = 0; i < arraySize; i++) {
		intArray[i] = rand() % 1000;
	}
	return 0;
}

void swap(int *x, int*y){ //swap함수 정의
	int z = *x; //교환을 위한 변수 z에 x값 저장
		*x = *y; //x에 y값 저장
		*y = z; // y에 z값 저장
}
void sortArray(int *intArray, int inputSize){ //sortArray함수 정의
	for (int i = 0; i < inputSize; i++){
		int *m = intArray+i; // 포인터 m에 최솟값 저장
		for (int j = i; j < inputSize; j++){ // 배열을 순차적으로 탐색하여 값을 비교하여 swap 함수를 통해 자리를 바꿔줌
			if (*(intArray+j) < *m)
				m = intArray+j;
			swap(m, intArray+i); // swap 함수 호출
		}
	}
}