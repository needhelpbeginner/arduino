/*작성자: 20240411 김민재
작성일: 2024.11.27.수요일
프로그램명: 암호문 만들기*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void enc(char* ordinary, char* secure) { //ordinary는 평문, secure은 암호문
    int i;
    for (i = 0; ordinary[i] != '\0'; i++) { //대문자인지 확인한다
        if (isalpha(ordinary[i]) && isupper(ordinary[i])) {
           secure[i] = ((ordinary[i] - 'A' + 5) % 26) + 'A';  //  암호화키 5
        }
        else {
            secure[i] = ordinary[i]; // 대문자가 아니라면 그대로 출력한다
        }
    }
    secure[i] = '\0'; 
}
void dec(char* secure, char* ordinary) {
    int i;
    for (i = 0; secure[i] != '\0'; i++) {
        if (isalpha(secure[i]) && isupper(secure[i])) {
            ordinary[i] = ((secure[i] - 'A' - 5 + 26) % 26) + 'A'; //5를 반대로 이동시켜 평문을 구한다
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
        printf("1. 암호화\n");
        printf("2. 복호화\n");
        printf("3. 종료\n");
        printf("----------------\n");
        printf("메뉴를 선택하세요 : ");
        scanf("%d", &choice);  

        if (choice == 1) {
            printf("평문을 입력하세요 : ");
            scanf("%s", ordinary); 

            if (strlen(ordinary) > 10) {
                printf("10글자 이내로 다시 입력해주세요.\n");
                continue;  // 메뉴로 돌아감
            }

            enc(ordinary, secure);
            printf("\n암호문 : %s\n", secure);  
        }
        else if (choice == 2) {
            printf("암호문을 입력하세요: ");
            scanf("%s", secure);  

            if (strlen(secure) > 10) {
                printf("10글자 이내로 다시 입력해주세요.\n");
                continue;// 메뉴로 돌아감
            }

            dec(secure, ordinary);  
            printf("\n평문 : %s\n", ordinary);  
        }
        else if (choice == 3) {
            printf("프로그램 종료\n");
            break; 
        }
        else {
            printf(" 다시 입력하세요.\n");
        }
    }
    return 0;
}
printf("암호문 만들기");