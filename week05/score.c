#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calSum(int *intArray, int arraySize); //�迭�� ���� ����ϴ� �Լ�

int calAvg(int *intArray, int arraySize); //�迭�� ����� ����ϴ� �Լ�

int findMin(int *intArray, int arraySize); //�迭���� �ּڰ��� ã�� �Լ�

int findMax(int *intArray, int arraySize); //�迭���� �ִ밪�� ã�� �Լ�

int main(){
	int arr[20]; //ũ�Ⱑ 20�� �迭 ����
	int arraySize; //1~20 ���̿��� ����� �迭 ���� ����

	srand((unsigned int)time((time_t*)NULL)); //seed value(������)
		
		printf("���ڸ� �Է��Ͻÿ�. : "); //��±���
		scanf_s("%d", &arraySize); //����� �迭 �Է� ����
		makeArray(arr, arraySize); //�迭 ����
		
		for (int i = 0; i < arraySize; i++) { //for���� �̿��� �迭�� �ݺ�����
			printf("%d\n", arr[i]);
		}

		int sum = calSum(arr, arraySize); //���� ����ϴ� �Լ��� �ҷ��ͼ� sum�� �Է�
		int avg = calAvg(arr, arraySize); //����� ����ϴ� �Լ��� �ҷ��ͼ� avg�� �Է�
		int min = findMin(arr, arraySize); //�ּڰ��� ����ϴ� �Լ��� �ҷ��ͼ� min�� �Է�
		int max = findMax(arr, arraySize); //�ִ��� ����ϴ� �Լ��� �ҷ��ͼ� max�� �Է�


		printf("�� : %d \n" , sum); //sum���
		printf("��� : %d \n", avg); //avg���
		printf("�ִ� : %d \n", max); //min���
		printf("�ּڰ� : %d \n", min); //max���
		return 0;
	}
	

int makeArray(int *intArray, int arraySize){ //1~1000������ �����߿��� �����ϰ� �迭�� ����
	for (int i = 0; i < arraySize; i++) {
		intArray[i] = rand() % 1000;
	}
	return 0;
}

int calSum(int *intArray, int arraySize){ //���� ����ϴ� �Լ�
	int Sum = 0;
	for (int i = 0; i < arraySize; i++){
		Sum = Sum + intArray[i];
	}
	return Sum;
}

int calAvg(int *intArray, int arraySize){ //����� ����ϴ� �Լ�
	int Avg;
	int sum = 0;
	for (int i = 0; i < arraySize; i++){
		sum = sum + intArray[i];
	}
	Avg = sum / arraySize;
	return Avg;
}

int findMin(int *intArray, int arraySize){ //�ּڰ��� ����ϴ� �Լ�
	int Min;
	Min = intArray[0];
	
	for (int i = 0; i < arraySize; i++){
		if (intArray[i] < Min)
			Min = intArray[i];
	}
	return Min;
}

int findMax(int *intArray, int arraySize){ //�ִ��� ����ϴ� �Լ�
	int Max;
	Max = intArray[0];

	for (int i = 0; i < arraySize; i++){
		if (intArray[i] > Max)
			Max = intArray[i];
	}
	return Max;
}