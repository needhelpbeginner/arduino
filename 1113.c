/*작성자: 20240411 김민재
작성일: 11.13
프로그램명: */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//파일 어떻게 쓰는지 잘 기억하기 fputc(' ',fp); /abc를 세로로 출력하기/fputs와 차이점은?
/*
int main(void) {
	FILE* fp = NULL;
	int c;
	fp = fopen("sample.txt", "w");

	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	else {
		printf("파일 열기 성공\n");
	}
	
	fputc('a', fp);
	fputc('\n', fp);
	fputc('b', fp);
	fputc('\n', fp);
	fputc('c', fp);
	
	fclose(fp);
	return 0;
}*/
/*int main(void) {
	FILE* fp = NULL;
	int c,i=1;

	fp = fopen("sample.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	while ((c = fgetc(fp)) != EOF) {
		if (c != '\n') { //개행문자와 열문자는 다르다.
			printf("%d", i);
			i++;
		}
		putchar(c);
	}
	
	fclose(fp);
	return 0;
}*/
/*int main(void) {
	if (remove("sample.txt") == -1) //실패한 경우
		printf("sample.txt를 삭제할 수 없습니다.\n");
	else
		printf("sample.txt를 삭제하였습니다.\n");
	return 0;
}*/
//1번 664p/다시 해보기
/*
int main(void) {
	FILE* fp = NULL;
	int c, i = 1;
	fp = fopen("proverbs.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패");
		return 1;
	}
	else {
		printf("파일 열기 성공");
	}
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') {
			putchar(c);
			printf("%d: ", i);
			i++;
		}
		else {
			putchar(c);
		}
	}
	return 0;
}*///형식화된 입출력안함
int main(void) {
	FILE* fp1, *fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("원본 파일 이름: ");
	scanf("%s", file1);

	printf("복사 파일 이름: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "원본 파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}
	if ((fp2 = fopen(file2, "w")) == NULL) {
		fprintf(stderr, "복사 파일 %s을 열 수 없습니다.\n", file2);
		exit(1);
	}
	while (fgets(buffer, 100, fp1) != NULL)
		fputs(buffer, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}