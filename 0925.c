/*�й�:20240411
�̸�: �����
���α׷���: */
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
	printf("����ȹ��ڿ��� %s\n", src);


	return 0;
	}*/


	/*#include <stdio.h>
	#include<ctype.h>
	int main(void) {
		int i=0;
		char name[100];
		//char address[100];

		printf("�̸��� ���� �ҹ��ڷ� �Է��Ͻÿ�: ");
		gets_s(name,100);

		while (name[i] != '\0') {
			if (islower(name[i]))
				printf("%c", topper(name[i]));
			else
				printf("%c", name[i]);
			i++;
		}


		/*printf("���� �����ϴ� �ּҸ� �Է��Ͻÿ�: ");
		gets_s(address,100);*/

/*
#include <stdio.h>
#include <ctype.h>
int count_word(char* s);
int main(void) {
	int wc = count_word("the c book...");
	printf("�ܾ��� ����: %d \n", wc);
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
/*�й�: 20240411 �����
���α׷���: ��� �빮�ڷ� ����ϴ� ���α׷� 0929*/

#include <stdio.h>
#include <ctype.h>
int count_word(char* s);//�Լ�:�ܾ� ������ ����
int main(void) {
	char str[100]; //�ִ� �Է��� �� �ִ� ���ڿ��� ���̸� 100���� ���Ѵ�.
	printf("���� ������ �Է��ϼ���: ");
	gets(str); //���ڿ��� �Է¹޴´�.
	for (int i = 0; str[i]; i++) {
		str[i] = toupper(str[i]); //�빮�ڷ� ��ȯ�ϴ� �Լ��� ����Ѵ�
	}

	printf("�빮�ڷ� �ٲٱ�: %s\n", str); //�빮�ڷ� ��ȯ�� ���ڿ��� ����Ѵ�
	int wc = count_word(str);
	printf("�ܾ�� %d���Դϴ�.\n", wc); //�ܾ� ���� ���
	return 0;
}
int count_word(char* s) {
	int wc = 0; //�ܾ� ������ 0���� �ʱ�ȭ ���ѵд�
	int in_word = 0; //���� �ܾ� �ȿ� �ִ��� ����

	for (int i = 0; s[i]; i++) {
		if (isalpha((unsigned char)s[i])) {
			if (!in_word) { //���ο� �ܾ� ����
				wc++;
				in_word = 1; //�ܾ� �ȿ� ����
			}
		}
		else {
			in_word = 0; //�ܾ� ��
		}
	}
	return wc; //�ܾ� ������ ��ȯ�Ѵ�
}