#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dup_check(char**sp, char*temp, int cnt); //dup_check �Լ� ����

int main(){
	char word[100];
	char *sp[100];
	int cnt;

	int i = 0;
	while (1){
		printf("�ܾ� �Է� : ");
		gets(word); //���ڿ� �Է�
		sp[i] = (char*)malloc(strlen(word) + 1); //���ڿ� ���� ���� �Ҵ�
		strcpy(sp[i], word); //���� �Ҵ� ������ ���ڿ� ����
		
		if ((strcmp(word, "end") == 0) || (i == 100)) //"end"�� �Է��ϰų� �ܾ���� 100�̸� ����
			break; 
		
		if (dup_check(sp, word, i)){ //�̹� �����ϴ� �ܾ� �� ��
			printf("�̹� �����ϴ� �ܾ��Դϴ�! \n");
			continue;
		}

		if ((i != 0) && (sp[i - 1][strlen(sp[i - 1]) - 1] != word[0])){ //ù��° �ܾ�� � �ܾ ��� ����,
			                                                            //���� �ܾ��� ������ ���ڰ� ���� �ܾ��� ù��° ���ڿ� ���� ���� ��
			printf("�ܾ� �ձⰡ �Ұ����մϴ�! \n");
			continue;
		}


		if (sp[i] == NULL){ //���� �Ҵ翡 �����ϸ� NULL ������ ��ȯ
			printf("�޸𸮰� �����մϴ�!"); 
			exit(1); // ���α׷� ����
		}
		
		i++; //i�� ����
	}
	cnt = i; //i�� cnt�� ����

	for (i = 0; i < cnt; i++)
		printf("%s ", sp[i]); //�Էµ� ���ڿ� ���

	for (i = 0; i < cnt; i++){ 
		free(sp[i]); //���� �Ҵ� ���� ��ȯ
	}

	return 0;
}

int dup_check(char**sp, char*temp, int cnt){ // dup_check �Լ� ����
	int i;

	for (i = 0; i < cnt; i++){ //�ߺ��ܾ� ã�� �ݺ���
		if (strcmp(temp, sp[i]) == 0)
			return 1;
	}
	return 0;
} //�̹� �ִ� �ܾ����� üũ�ϴ� �޼ҵ�