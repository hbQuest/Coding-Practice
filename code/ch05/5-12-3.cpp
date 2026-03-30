#include<stdio.h>

void NhapMang (int a[], int &n)
{
    do
    {
        printf("Nhap so phan tu: ");
        scanf("%d", &n);
        if(n <= 0 || n > 100)
        {
            printf("So phan tu khong hop le. Xin kiem tra lai !\n");
        }
    }while(n <= 0 || n > 100);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

bool kiemTraTangDan(int b[], int n) {
    for (int i = 1; i < n; i++) {
        if (b[i] <= b[i-1]) {
            return false;
        }
    }
    return true;
}

void taoMangB(int a[], int b[], int n) {
    if (n == 1) {
        b[0]= 0;
        return;
    }
    b[0] = a[1];
    b[n-1] = a[n-2];
    for (int i = 1; i < n-1; i++) {
        b[i] = a[i-1] + a[i+1];
    }
}

// 5.12.1
void TaoMangLe(int a[], int le[], int n, int &m) {
    int dem = 0;
    for (int i = 0; i< n; i++) {
        if (a[i]%2 != 0) {
            le[dem++] = a[i];
        }
    }
    m = dem;
}

int main()
{
    int a[100];
    int n;

    NhapMang(a, n);
    XuatMang(a, n);

    int b[100], m = n;
    printf("Tao mang b voi b[i] = tong phan tu lan can cua a[i]:\n");
    taoMangB(a,b,n);
    XuatMang(b,n);

    int le[n], nLe;
    printf("Mang le cua mang a:\n");
    TaoMangLe(a,le,n,nLe);
    XuatMang(le,nLe);


    return 0;
}