/*�ۼ���: 20240411 �����
�ۼ���: 11.13
���α׷���: */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���� ��� ������ �� ����ϱ� fputc(' ',fp); /abc�� ���η� ����ϱ�/fputs�� ��������?
/*
int main(void) {
	FILE* fp = NULL;
	int c;
	fp = fopen("sample.txt", "w");

	if (fp == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	else {
		printf("���� ���� ����\n");
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
		printf("���� ���� ����\n");
	else
		printf("���� ���� ����\n");

	while ((c = fgetc(fp)) != EOF) {
		if (c != '\n') { //���๮�ڿ� �����ڴ� �ٸ���.
			printf("%d", i);
			i++;
		}
		putchar(c);
	}
	
	fclose(fp);
	return 0;
}*/
/*int main(void) {
	if (remove("sample.txt") == -1) //������ ���
		printf("sample.txt�� ������ �� �����ϴ�.\n");
	else
		printf("sample.txt�� �����Ͽ����ϴ�.\n");
	return 0;
}*/
//1�� 664p/�ٽ� �غ���
/*
int main(void) {
	FILE* fp = NULL;
	int c, i = 1;
	fp = fopen("proverbs.txt", "r");
	if (fp == NULL) {
		printf("���� ���� ����");
		return 1;
	}
	else {
		printf("���� ���� ����");
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
}*///����ȭ�� ����¾���
int main(void) {
	FILE* fp1, *fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("���� ���� �̸�: ");
	scanf("%s", file1);

	printf("���� ���� �̸�: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}
	if ((fp2 = fopen(file2, "w")) == NULL) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}
	while (fgets(buffer, 100, fp1) != NULL)
		fputs(buffer, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}