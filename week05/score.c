#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calSum(int *intArray, int arraySize); //배열의 합을 계산하는 함수

int calAvg(int *intArray, int arraySize); //배열의 평균을 계산하는 함수

int findMin(int *intArray, int arraySize); //배열에서 최솟값을 찾는 함수

int findMax(int *intArray, int arraySize); //배열에서 최대값을 찾는 함수

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

		int sum = calSum(arr, arraySize); //합을 계산하는 함수를 불러와서 sum에 입력
		int avg = calAvg(arr, arraySize); //평균을 계산하는 함수를 불러와서 avg에 입력
		int min = findMin(arr, arraySize); //최솟값을 계산하는 함수를 불러와서 min에 입력
		int max = findMax(arr, arraySize); //최댓값을 계산하는 함수를 불러와서 max에 입력


		printf("합 : %d \n" , sum); //sum출력
		printf("평균 : %d \n", avg); //avg출력
		printf("최댓값 : %d \n", max); //min출력
		printf("최솟값 : %d \n", min); //max출력
		return 0;
	}
	

int makeArray(int *intArray, int arraySize){ //1~1000까지의 숫자중에서 랜덤하게 배열에 삽입
	for (int i = 0; i < arraySize; i++) {
		intArray[i] = rand() % 1000;
	}
	return 0;
}

int calSum(int *intArray, int arraySize){ //합을 계산하는 함수
	int Sum = 0;
	for (int i = 0; i < arraySize; i++){
		Sum = Sum + intArray[i];
	}
	return Sum;
}

int calAvg(int *intArray, int arraySize){ //평균을 계산하는 함수
	int Avg;
	int sum = 0;
	for (int i = 0; i < arraySize; i++){
		sum = sum + intArray[i];
	}
	Avg = sum / arraySize;
	return Avg;
}

int findMin(int *intArray, int arraySize){ //최솟값을 계산하는 함수
	int Min;
	Min = intArray[0];
	
	for (int i = 0; i < arraySize; i++){
		if (intArray[i] < Min)
			Min = intArray[i];
	}
	return Min;
}

int findMax(int *intArray, int arraySize){ //최댓값을 계산하는 함수
	int Max;
	Max = intArray[0];

	for (int i = 0; i < arraySize; i++){
		if (intArray[i] > Max)
			Max = intArray[i];
	}
	return Max;
}