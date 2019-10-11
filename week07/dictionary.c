#include <stdio.h>

int main() {
	char dic[17] = { 0 }; //배열선언
	char temp[200][201]= { 0 }; // 단어 저장
	int n = 0; 
	int p = 0;
	int boolean = 1;

	for (int i = 1; ;  i++) {
		printf("단어 입력 : ");
		gets(dic); //함수 호출
		n = strlen(dic); //문자열의 길이 계산함수
		
		if (n > 15){
			printf("15자리 이하로 입력하시오.\n");
		}
		else {
			dic[n] = ' '; //띄어쓰기
			dic[n + 1] = '\0'; //널문자 저장
			if (i == 1) { 
				strcpy(temp[p++], dic); 
				temp[p][0] = '0'; //문자열 분할
			}
			else {
				for (int j = 0; j < p; j++) { //사전순서대로 정렬하는 반복문
					if (strcmp(temp[j], dic) == 1) { 
						char temp2[201] = { 0 };
						strcpy(temp2, temp[j]); 
						strcpy(temp[j], dic); 
						strcpy(temp[p++], temp2); 

					    int sum = 0;
						for (int k = 0; k != j; k++) { //문자열의 총 길이를 계산
							sum = sum + strlen(temp[k]);
						}
						temp[p][0] = '0'; //문자열 분할
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
			
			printf("현재까지 문자열 : ");
			
			int m = 0;
			while (temp[m][0] != '0'){ //문자열 출력
				printf("%s", temp[m]);
				m++;
			}
			printf("\n");
		}
	}
}