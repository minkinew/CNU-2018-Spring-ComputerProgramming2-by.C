#include <stdio.h>

count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]); //count_num �Լ� 

int main(){
	int ary1[3][4] = { // ary1�迭 ���� �� �ʱ�ȭ
		{ 15, 3, 9, 11 },
		{ 23, 7, 10, 12 },
		{ 0, 17, 55, 24 }
	};
	
	int ary2[3][4] = { //ary2 �迭 ���� �� �ʱ�ȭ
		{ 13, 8, 9, 15 },
		{ 23, 0, 10, 11 },
		{ 29, 17, 43, 3 }
	};

	int same_num[12][2]; //�ߺ��� ��, ���� �����ϴ� �迭 
	int cnt;
	cnt = count_num(ary1, ary2, same_num); //cnt ����

	printf("��ġ�ϴ� ��ȣ�� �� : %d\n", cnt);
	printf("�迭������ ��ġ(��, ��)...\n");

	for (int i = 0; i < cnt; i++){ 
		printf("(%d, %d)\n", same_num[i][0], same_num[i][1]);
	}
	return 0;
}

count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]){ //count_num �Լ� ���� 
	int count = 0;

	for (int i = 1; i < 4; i++){ //���� ��ġ�� ���� ���� �� �� ������ ��� �迭�� �����ϴ� �ݺ���
		for (int j = 1; j < 5; j++){
			if (ary1[i-1][j-1] == ary2[i-1][j-1]){ //��, ���� ���� ���� ��
				same_num[count][0] = i-1;
				same_num[count][1] = j-1;
				count++;
			}
		}
	}
	return count;
} //�ʱ�ȭ�� 2���� 2���� �迭���� ���� ��ġ�� ���� �ִ� ��� �׼��� ��� �迭�� �����ϰ� ������ ��ȯ
