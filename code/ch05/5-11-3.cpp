#include<stdio.h>
#define MAX 100

void input (int a[], int &n)
{
    do
    {
        printf("Nhap so phan tu: ");
        scanf("%d", &n);
        if(n <= 0 || n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    }while(n <= 0 || n > MAX);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

bool kiemTraTangDan(int b[], int n) {
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i-1]) {
            return false;
        }
    }
    return true;
}

void lietKeMangConTangDan(int a[], int n) {
    int b[MAX], nb;
    for (int k = 0; k < n; k++) {
       for (int i = 1; i <= n; i++) {
            int t = 0;
            for (int j = k; j < i; j++) {
                b[t] = a[j];
                t++;
            }
            if (kiemTraTangDan(b, t)) {
                display(b, t);
            }
        } 
    }
}

int main()
{
    int n;
    int a[MAX];

    input(a, n);
    display(a, n);
    printf("\nLiet ke mang con tang dan:\n");
    lietKeMangConTangDan(a, n);

    return 0;
}