#include <stdio.h>

int main(){
	int distance, speed, hour, min; //�ð�, �ӵ�, �ð�, �� ��������
	double sec, getTime; //��, getTime ���� ����
    
	printf("�Ÿ��� �ӷ��� �Է��Ͻÿ� : \n");
	scanf("%d %d", &distance, &speed);
	
	getTime = (double)distance / (double)speed; //�Ÿ��� �ӷ��� �ð��� ���� ������ ��ȯ

	hour = (int)getTime;  //���������� ��ȯ�� �ð��� ���
	getTime = getTime - hour;
	getTime = getTime * 60.0;
	min = (int)getTime; //���������� ��ȯ�� �и� ȯ��
	getTime = getTime - min;
	getTime = getTime * 60.0;
	sec = (double)getTime; //�Ǽ������� ��ȯ�� �� ȯ��

	printf("�ҿ�ð��� %d�ð� %d�� %.3lf���Դϴ�. \n", hour, min, sec);
	
}