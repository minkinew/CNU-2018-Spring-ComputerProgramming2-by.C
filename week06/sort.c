#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int*y); //swap�Լ� ����

void sortArray(int *intArray, int inputSize); //sortArray �Լ� ����

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

	sortArray(arr, arraySize); //sortArray�Լ� ȣ��
	printf("��ȭ�� �� : \n");
	
	for (int i = 0; i < arraySize; i++){ //��ȭ�� �迭�� for���� �̿��� �ݺ�����
		printf("%d\n", arr[i]);
	}

	return 0;
}


int makeArray(int *intArray, int arraySize){ //1~1000������ �����߿��� �����ϰ� �迭�� ����
	for (int i = 0; i < arraySize; i++) {
		intArray[i] = rand() % 1000;
	}
	return 0;
}

void swap(int *x, int*y){ //swap�Լ� ����
	int z = *x; //��ȯ�� ���� ���� z�� x�� ����
		*x = *y; //x�� y�� ����
		*y = z; // y�� z�� ����
}
void sortArray(int *intArray, int inputSize){ //sortArray�Լ� ����
	for (int i = 0; i < inputSize; i++){
		int *m = intArray+i; // ������ m�� �ּڰ� ����
		for (int j = i; j < inputSize; j++){ // �迭�� ���������� Ž���Ͽ� ���� ���Ͽ� swap �Լ��� ���� �ڸ��� �ٲ���
			if (*(intArray+j) < *m)
				m = intArray+j;
			swap(m, intArray+i); // swap �Լ� ȣ��
		}
	}
}