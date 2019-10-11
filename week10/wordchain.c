#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dup_check(char**sp, char*temp, int cnt); //dup_check 함수 선언

int main(){
	char word[100];
	char *sp[100];
	int cnt;

	int i = 0;
	while (1){
		printf("단어 입력 : ");
		gets(word); //문자열 입력
		sp[i] = (char*)malloc(strlen(word) + 1); //문자열 저장 공간 할당
		strcpy(sp[i], word); //동적 할당 영역에 문자열 복사
		
		if ((strcmp(word, "end") == 0) || (i == 100)) //"end"를 입력하거나 단어수가 100이면 종료
			break; 
		
		if (dup_check(sp, word, i)){ //이미 존재하는 단어 일 때
			printf("이미 존재하는 단어입니다! \n");
			continue;
		}

		if ((i != 0) && (sp[i - 1][strlen(sp[i - 1]) - 1] != word[0])){ //첫번째 단어는 어떤 단어도 상관 없음,
			                                                            //이전 단어의 마지막 문자가 현재 단어의 첫번째 문자와 같지 않을 때
			printf("단어 잇기가 불가능합니다! \n");
			continue;
		}


		if (sp[i] == NULL){ //동적 할당에 실패하면 NULL 포인터 반환
			printf("메모리가 부족합니다!"); 
			exit(1); // 프로그램 종료
		}
		
		i++; //i값 증가
	}
	cnt = i; //i를 cnt에 대입

	for (i = 0; i < cnt; i++)
		printf("%s ", sp[i]); //입력된 문자열 출력

	for (i = 0; i < cnt; i++){ 
		free(sp[i]); //동적 할당 영역 반환
	}

	return 0;
}

int dup_check(char**sp, char*temp, int cnt){ // dup_check 함수 정의
	int i;

	for (i = 0; i < cnt; i++){ //중복단어 찾는 반복문
		if (strcmp(temp, sp[i]) == 0)
			return 1;
	}
	return 0;
} //이미 있는 단어인지 체크하는 메소드