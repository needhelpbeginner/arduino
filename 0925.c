/*학번:20240411
이름: 김민재
프로그램명: */
/*#include<stdio.h>
int main(void) {
	int i;
	char str[4];

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';

	for (i = 0; i < 4; i++) {
		printf("%c",str[i]);
	}
	return 0;


	for (i = 0; src[i] != '\0'; i++)
	dst[i] = src[i];
	dst[i] = '\0';
}*/

/*#include<stdio.h>
int main(void) {
	char * src = "Action speaks louder than words";
	int i=0;
	int count = 0;

	/*for (i = 0; src[i] != '\0'; i++)
	dst[i] = src[I];
	dst[i] = '\0';*/

	/*src = "Andong National University";
	printf("변경된문자열은 %s\n", src);


	return 0;
	}*/


	/*#include <stdio.h>
	#include<ctype.h>
	int main(void) {
		int i=0;
		char name[100];
		//char address[100];

		printf("이름을 영문 소문자로 입력하시오: ");
		gets_s(name,100);

		while (name[i] != '\0') {
			if (islower(name[i]))
				printf("%c", topper(name[i]));
			else
				printf("%c", name[i]);
			i++;
		}


		/*printf("현재 거주하는 주소를 입력하시오: ");
		gets_s(address,100);*/

/*
#include <stdio.h>
#include <ctype.h>
int count_word(char* s);
int main(void) {
	int wc = count_word("the c book...");
	printf("단어의 개수: %d \n", wc);
	return 0;
}
int count_word(char* s) {
	int i, wc = 0, waiting = 1;
	for (i = 0; s[i] != NULL; ++i)
		if (isalpha(s[i])) {
			if (waiting) {
				wc++;
				waiting = 0;
			}
		}
		else
			waiting = 1;
	return wc;
}*/
/*학번: 20240411 김민재
프로그램명: 모두 대문자로 출력하는 프로그램 0929*/

#include <stdio.h>
#include <ctype.h>
int count_word(char* s);//함수:단어 개수를 센다
int main(void) {
	char str[100]; //최대 입력할 수 있는 문자열의 길이를 100으로 정한다.
	printf("영어 문장을 입력하세요: ");
	gets(str); //문자열을 입력받는다.
	for (int i = 0; str[i]; i++) {
		str[i] = toupper(str[i]); //대문자로 변환하는 함수를 사용한다
	}

	printf("대문자로 바꾸기: %s\n", str); //대문자로 변환된 문자열을 출력한다
	int wc = count_word(str);
	printf("단어는 %d개입니다.\n", wc); //단어 개수 출력
	return 0;
}
int count_word(char* s) {
	int wc = 0; //단어 개수를 0으로 초기화 시켜둔다
	int in_word = 0; //현재 단어 안에 있는지 여부

	for (int i = 0; s[i]; i++) {
		if (isalpha((unsigned char)s[i])) {
			if (!in_word) { //새로운 단어 시작
				wc++;
				in_word = 1; //단어 안에 있음
			}
		}
		else {
			in_word = 0; //단어 밖
		}
	}
	return wc; //단어 개수를 반환한다
}