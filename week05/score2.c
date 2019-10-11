#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m = 999;

int calSum(int *intArray, int arraySize); //배열의 합을 계산하는 함수

int calAvg(int *intArray, int arraySize); //배열의 평균을 계산하는 함수

int findMin(int *intArray, int arraySize); //배열의 최댓값을 찾는 함수

int findMax(int *intArray, int arraySize); //배열에서 최댓값을 찾는 함수


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
	int min = findMin(arr, arraySize); //최댓값을 계산하는 함수를 불러와서 max에 입력
	int max = findMax(arr, arraySize); //최댓값을 계산하는 함수를 불러와서 max에 입력


	printf("합 : %d \n", sum); //sum출력
	printf("평균 : %d \n", avg); //avg출력
	printf("최솟값 : %d \n", min); //avg출력
	printf("최댓값 : %d \n", max); //min출력
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
	if (arraySize == 0) //arraySize가 0일떄 m값을 출력
		return m;
	if (intArray[arraySize -1] < m)  
		m = intArray[arraySize-1]; //arraysize-1을 m값을 비교해서 m보다 작으면 m값에 대입
		return findMin(intArray, arraySize - 1); //arraySize를 1낮추면서 재귀함수를 실행
	
}
int findMax(int *intArray, int arraySize) //최댓값을 계산하는 함수
{
	int a, b;
	
	if (arraySize == 1)
		return *intArray; //arraySize가 1이면 return

	if (arraySize % 2 == 0) { // arraySize 이 짝수일때. 두 개의 부분으로 나눔
		a = findMax(intArray, arraySize / 2);
		b = findMax(intArray + arraySize / 2, arraySize / 2);
	}
	else { // arraySize 이 홀수일때. 두 개의 부분으로 나눔
		a = findMax(intArray, (arraySize + 1) / 2); 
		b = findMax(intArray + (arraySize + 1) / 2, (arraySize - 1) / 2);
	}
	return (a >= b) ? a : b; // 두 개의 값 중에 큰 값을 return 한다.(MAX)
}
