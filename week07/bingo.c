#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void makeBingo(int * bingoArray, int inputSize); // void makeBingo �Լ� ���� 
void printBingo(int * bingoArray, int inputSize); // void printBingo �Լ� ���� �������� ��� �Լ�
int checkBingo(int * bingoArray, int inputSize); // int checkBingo�Լ� ���� 
int getRandomNumber(int * prevNumberList); // int getRandomNumber 
int getUserSelectNumber(int * prevNumberList); // int getUserSelectNumber

int main() {

	srand((unsigned int)time((time_t*)NULL)); //���α׷� ���� �ø��� ������ ���� �߻�

	int Bingo[400] = { 0 };
	int bingosize;
	//�迭 �� ���� ����

	printf("������ ����� �Է��ϼ��� : "); 
	scanf("%d", &bingosize); 

	makeBingo(Bingo, bingosize); // makeBingo() �Լ� ȣ��
	checkBingo(Bingo, bingosize); // checkBingo() �Լ� ȣ��

	return 0;
}


void makeBingo(int * bingoArray, int inputSize) { //void makeBingo �Լ� ����
	int Bingo2[400] = { 0 };
	int count = 0;
	int p = 0;
	//���� ����

	while (count < (inputSize * inputSize)) {
		p = rand() % (inputSize * inputSize) + 1; // �������� p�� ����

		if (Bingo2[p - 1] == 0) { // �ߺ� ���� ����ó��
			++Bingo2[p - 1];
			bingoArray[count++] = p;
		}
	}
	printBingo(bingoArray, inputSize); //printBingo() ȣ��
} // �������� ����

void printBingo(int * bingoArray, int inputSize) { // void printBingo �Լ� ���� 
	for (int i = 0; i < inputSize * inputSize; i++) {
		if (bingoArray[i] == -5) // bingoArray[i]�� -5�� �� '*' ���
			printf("%4c", '*'); 
		else
			printf("%4d", bingoArray[i]); // �׷��� ������ bingoArray[i] ���

		if (i % inputSize == inputSize - 1)
			printf("\n");  // �ٹٲ�
	}
} // �������� ���

int checkBingo(int * bingoArray, int inputSize) { // int checkBingo �Լ� ����
	int Bingocheck[400] = { 0 };
	int checkNum = 0;
	int bingo = 0;
	int Number;
	int bingoNum;
	//���� ����

	Bingocheck[inputSize * inputSize] = -1;

	while (1) {
		bingoNum = 0;

		printf("���� ���� ����� ����[1:����][2:������Է�] : ");
		scanf("%d", &Number);

		if (Number == 1)
			bingoNum = getRandomNumber(Bingocheck); // 1�� �Է����� ��
		else if (Number == 2)
			bingoNum = getUserSelectNumber(Bingocheck); // 2�� �Է����� ��
	

		if (bingoNum == 0) // 1, 2���� ������ ��ȣ�� �Է����� ��
			printf("�ٽ� �Է� �ϼ���\n");

		else if (bingoNum == -1) // �ߺ� ���ڸ� �Է����� ��
			printf("�̹� �Էµ� �����Դϴ�\n");

		else { // ���������� �Է����� ��
			for (int i = 0; i < (inputSize * inputSize); i++) {
				if (bingoArray[i] == bingoNum)
					bingoArray[i] = -5;
			}

			switch (1) { // ���� ���� Ȯ��
			case 1: // ���� ���� Ȯ��
				for (int i = 0; i < inputSize; i++) {
					for (int j = 0; j < (inputSize * inputSize); j = j + inputSize) {
						if (bingoArray[i + j] == -5)
							++checkNum;
					}
					if (checkNum == inputSize) { // ���� ���� �Ǿ��� ��
						++bingo; 
						break;
					}
					checkNum = 0; // 0���� �ʱ�ȭ
				}

				if (checkNum == inputSize) // ����
					break;

			case 2: // ���� ���� Ȯ��
				for (int i = 0; i < (inputSize * inputSize); i = i + inputSize) {
					for (int j = 0; j < inputSize; j++) {
						if (bingoArray[i + j] == -5)
							++checkNum;
					}
					if (checkNum == inputSize) { // ���� ���� �Ǿ��� ��
						++bingo; 
						break;
					}
					checkNum = 0; // 0���� �ʱ�ȭ
				}

				if (checkNum == inputSize) // Ž�� ����,
					break;

			case 3: // �밢�� 1�� ���� ���� Ȯ��
				for (int i = inputSize - 1; i < (inputSize * inputSize); i = i + inputSize - 1) {
					if (bingoArray[i] == -5)
						++checkNum;
				}

				if (checkNum == inputSize) { // �밢�� 1�� ������ ���� �Ǿ��� ��
					++bingo; 
					break;
				}
				checkNum = 0; // 0���� �ʱ�ȭ

			case 4: // �밢�� 2�� ���� ���� Ȯ�� 
				for (int i = 0; i < (inputSize * inputSize); i = i + inputSize + 1) {
					if (bingoArray[i] == -5)
						++checkNum;
				}

				if (checkNum == inputSize) { // �밢�� 2�� ������ ���� �Ǿ��� ��
					++bingo; 
					break;
				}
				checkNum = 0; //0���� �ʱ�ȭ
			}

			if (bingo != 0) {
				printf("����!\n"); //"����" ���
				printBingo(bingoArray, inputSize); // printBingo �Լ� ȣ��
				break;
			}
		}
	}
	return 0;
} // ���� Ȯ��

int getRandomNumber(int * prevNumberList) { // int getUserSelectNumber �Լ� ���� 
	int m = 0;
	int size = 0;
	int j = 1;

	for (size = 0; prevNumberList[size] != -1; size++);

	while (1) {
		int check = 0;
		m = rand() % size + 1; 

		for (int i = 1; i < size-1; i++)
		if (prevNumberList[i-1] == m) {
			++check;
			break;
		}

		if (check == 0)
			break;
	}

	printf("���� ���ڸ� ���� : %d\n", m);

	while (1){
		if (prevNumberList[j - 1] == 0) {
			prevNumberList[j - 1] = m;
			break;
		}
		j++;
	}

	return m;
} // ������� �������� ���� ���ڵ���, �ϳ��� �����ϰ� �����ؼ� ��ȯ

int getUserSelectNumber(int * prevNumberList) { // int getUserSelectNumber �Լ� ���� 
	int m;
	int size = 0; 
	int check = 0;
	int j = 1;

	for (size = 0; prevNumberList[size] != -1; size++);

	printf("����� ���� ���� �Է� : ");
	scanf("%d", &m);

	for (int i = 1; i < size-1; i++)
	if (m == prevNumberList[i-1]) {
		++check;
		break;
	}

	if (check != 0)
		m = -1;
	else {
		while (1){
			if (prevNumberList[j - 1] == 0) {
				prevNumberList[j - 1] = m;
				break;
			}
			j++;
		}
	}
	return m;
} //���� ��ȣ�� �Է¹޾� ��ȯ