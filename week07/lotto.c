#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void makeLottoNumber(int *lottoNums); //makeLottoNumber �Լ� ����
void sortArray(int *lottoNums); //sortArray �Լ� ����
void swap(int *x, int*y); //swap �Լ� ����
int checkLottoNumber(int *lottoNums); //checkLottoNumber �Լ� ����

int main(){
	int lottoNums[6]; //�迭 ����
	
	makeLottoNumber(lottoNums); //makeLottoNumber �Լ� ȣ��

	checkLottoNumber(lottoNums); //checkLottoNumber �Լ� ȣ��
}
void makeLottoNumber(int *lottoNums){ //makeLottoNumber �Լ� ����
	int m; //���� ����

	srand((unsigned)time(NULL));  //srand �Լ�

	for (int i = 0; i < 6; i++){ //�ߺ��� ������ ������ �迭 ����
	again:;
		m = rand() % 45 + 1;
		for (int j = 0; j < i - 1; j++)
		if (m == lottoNums[j])
			goto again; // �ߺ� ���� �߰� �� again:���� ���ư�
				lottoNums[i] = m;	
		}
	sortArray(lottoNums); //sortArray �Լ� ȣ��
	}


void sortArray(int *lottoNums){  //sortArray �Լ� ����
	for (int i = 0; i < 6; i++){
		int *k = lottoNums + i;  //������ k�� �ּڰ� ����
		for (int j = i; j < 6; j++){ //�迭�� ���������� Ž���ؼ� ���� ���Ͽ� swap�Լ��� ���� �ڸ��� �ٲ���
			if (*(lottoNums + j) < *k)
				k = lottoNums + j;
			swap(k, lottoNums + i);  //swqp�Լ� ȣ��
		}
	}
}

void swap(int *x, int*y){ //swap�Լ� ����
	int z = *x; //��ȯ�� ���� ���� z�� x�� ����
	*x = *y; //x�� y�� ����
	*y = z; // y�� z�� ����
}

int checkLottoNumber(int *lottoNums){ //checkLottoNumber �Լ� ����
	int lottoA[6]; //�迭 A ����
	int lottoB[6]; //�迭 B ����
	int count = 0; //count ���� ����

	for (int i = 0; i < 6; i++){ //�迭 A�� �迭 B�� ���� �� �ߺ� ���� ��Ȯ��
		printf("��ȣ �Է� : \n");
		scanf("%d", &lottoA[i]);
		lottoB[i] = lottoA[i];

		if (lottoA[i] > 0 && lottoA[i] <= 45){ //�迭 A�� ���� 1~45�� ���� �� ��
			for (int j = 0; j < i; j++){
				if (lottoB[j] == lottoA[i]){ //�迭 B�� �迭 A�� ���� ���� ��
					printf("���� ��ȣ�� �ֽ��ϴ�.\n");
					i--;
					break;
				}
			}
		}
		else { //1~45�� ���ڰ� �ƴ� ��
			printf("1���� 45������ ���� �Է��ϼ���.\n");
			i--;
		}
		for (int j = 0; j < 6; j++) //�迭 A�� ���� �ζǹ�ȣ ���� ���ؼ� ��� ������ Ȯ��
			if (lottoA[i] == lottoNums[j] )
				count ++;
	}
	for (int i = 0; i < 6; i++){ //�ζǹ�ȣ ���� ����
		printf("%3d", lottoNums[i]);
	}
	printf("\n");
	printf("�� %d���� �´� ���ڰ� �ֽ��ϴ�.\n", count); 
}
