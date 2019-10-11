#include <stdio.h>
#include <string.h>

void invertedOutput(char str[]);

int main(){
	char c[100] = { 0 }; //문자열 배열 선언(나머지 값들은 0으로 초기화)
	printf("한 줄을 입력하세요. >>\n");
	gets(c); //빈칸을 포함한 문자열 입력
	printf("위에서 입력한 문자열을 거꾸로 출력합니다.\n");
	
	invertedOutput(c); //invertedOutput함수 호출
	
	return 0;
}

void invertedOutput(char str[]){
	char reverse[100]= {0}; //새로운 문자열 배열 선언(나머지 값들은 0으로 초기화)
	int len = strlen(str); //배열의 길이를 len변수에 초기화
	
	for (int i = len-1 , j = 0; i >= 0; i--,j++){
		reverse[j] = str[i]; //기존의 배열에 문자열을 새로운 배열에 역순으로 대입
	}
	puts(reverse); //새로운 배열에 저장된 문자열 출력
}