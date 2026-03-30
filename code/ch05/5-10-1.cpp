#include <stdio.h>
#define MAX 100

void input(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    putchar('\n');
}

void doiCho(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void doiCho1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            doiCho(a[0], a[i]);
            break;
        }
    }

}

int main() {
    int mangA[MAX];
    int n;
    printf("Xin nhap mang A:\n");
    input(mangA,n);
    display(mangA,n);
    printf("Mang A sau di chuyen so 1 ve dau:\n");
    doiCho1(mangA,n);
    display(mangA,n);

    return 0;
}