#include <stdio.h>

int main() {
	char dic[17] = { 0 }; //�迭����
	char temp[200][201]= { 0 }; // �ܾ� ����
	int n = 0; 
	int p = 0;
	int boolean = 1;

	for (int i = 1; ;  i++) {
		printf("�ܾ� �Է� : ");
		gets(dic); //�Լ� ȣ��
		n = strlen(dic); //���ڿ��� ���� ����Լ�
		
		if (n > 15){
			printf("15�ڸ� ���Ϸ� �Է��Ͻÿ�.\n");
		}
		else {
			dic[n] = ' '; //����
			dic[n + 1] = '\0'; //�ι��� ����
			if (i == 1) { 
				strcpy(temp[p++], dic); 
				temp[p][0] = '0'; //���ڿ� ����
			}
			else {
				for (int j = 0; j < p; j++) { //����������� �����ϴ� �ݺ���
					if (strcmp(temp[j], dic) == 1) { 
						char temp2[201] = { 0 };
						strcpy(temp2, temp[j]); 
						strcpy(temp[j], dic); 
						strcpy(temp[p++], temp2); 

					    int sum = 0;
						for (int k = 0; k != j; k++) { //���ڿ��� �� ���̸� ���
							sum = sum + strlen(temp[k]);
						}
						temp[p][0] = '0'; //���ڿ� ����
						boolean = -1;
						break;
					}
				}

				if (boolean == 1) { 
					strcpy(temp[p++], dic); 
					temp[p][0] = '0'; 
				}
				boolean = 1;
			}
			
			printf("������� ���ڿ� : ");
			
			int m = 0;
			while (temp[m][0] != '0'){ //���ڿ� ���
				printf("%s", temp[m]);
				m++;
			}
			printf("\n");
		}
	}
}