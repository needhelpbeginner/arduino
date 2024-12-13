/*�ۼ���: 20240411 �����
�ۼ���: 2024.11.27.������
���α׷���: ��ȣ�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void enc(char* ordinary, char* secure) { //ordinary�� ��, secure�� ��ȣ��
    int i;
    for (i = 0; ordinary[i] != '\0'; i++) { //�빮������ Ȯ���Ѵ�
        if (isalpha(ordinary[i]) && isupper(ordinary[i])) {
           secure[i] = ((ordinary[i] - 'A' + 5) % 26) + 'A';  //  ��ȣȭŰ 5
        }
        else {
            secure[i] = ordinary[i]; // �빮�ڰ� �ƴ϶�� �״�� ����Ѵ�
        }
    }
    secure[i] = '\0'; 
}
void dec(char* secure, char* ordinary) {
    int i;
    for (i = 0; secure[i] != '\0'; i++) {
        if (isalpha(secure[i]) && isupper(secure[i])) {
            ordinary[i] = ((secure[i] - 'A' - 5 + 26) % 26) + 'A'; //5�� �ݴ�� �̵����� ���� ���Ѵ�
        }
        else {
            ordinary[i] = secure[i];
        }
    }
    ordinary[i] = '\0'; 
}
int main() {
    int choice; 
    char ordinary[11], secure[11];  

    while (1) {  
      printf("\n---------------\n");
        printf("1. ��ȣȭ\n");
        printf("2. ��ȣȭ\n");
        printf("3. ����\n");
        printf("----------------\n");
        printf("�޴��� �����ϼ��� : ");
        scanf("%d", &choice);  

        if (choice == 1) {
            printf("���� �Է��ϼ��� : ");
            scanf("%s", ordinary); 

            if (strlen(ordinary) > 10) {
                printf("10���� �̳��� �ٽ� �Է����ּ���.\n");
                continue;  // �޴��� ���ư�
            }

            enc(ordinary, secure);
            printf("\n��ȣ�� : %s\n", secure);  
        }
        else if (choice == 2) {
            printf("��ȣ���� �Է��ϼ���: ");
            scanf("%s", secure);  

            if (strlen(secure) > 10) {
                printf("10���� �̳��� �ٽ� �Է����ּ���.\n");
                continue;// �޴��� ���ư�
            }

            dec(secure, ordinary);  
            printf("\n�� : %s\n", ordinary);  
        }
        else if (choice == 3) {
            printf("���α׷� ����\n");
            break; 
        }
        else {
            printf(" �ٽ� �Է��ϼ���.\n");
        }
    }
    return 0;
}
printf("��ȣ�� �����");