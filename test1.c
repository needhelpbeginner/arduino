#include <stdio.h>
int* mid(int* arr);
int main() {
    int arr[3];
    int* median;

    printf("�� ���� ������ �Է��ϼ���: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &arr[i]);
    }

    median = mid(arr);

    printf("�߾Ӱ�: %d\n", *median);

    return 0;
}
int* mid(int* arr) {
    int* a = arr;
    int* b = arr + 1;
    int* c = arr + 2;

    if ((*a <= *b && *b <= *c) || (*c <= *b && *b <= *a)) {
        return b;
    }
    else if ((*b <= *a && *a <= *c) || (*c <= *a && *a <= *b)) {
        return a;
    }
    else {
        return c;
    }
}
printf("hello world");