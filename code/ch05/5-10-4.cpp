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
        printf("%4d", a[i]);
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void daoNguocMang(int a[], int n)
{
    for (int i = 0, j = n-1; i < j; i++,j--) {
        swap(a[i], a[j]);
    }
}

int main()
{
    int n;
    int a[MAX];

    input(a, n);
    display(a, n);
    daoNguocMang(a, n);
    printf("\nDao nguoc mang: ");
    display(a, n);

    return 0;
}