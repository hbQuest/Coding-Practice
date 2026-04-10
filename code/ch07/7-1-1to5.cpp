#include <stdio.h>
#include <math.h>

void nhap(int a[][100], int&n) {
    do {
        printf("Nhap so dong va cot n: ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("So dong/cot khong hop le! Xin nhap lai!");
        }
    } while(n < 1 || n > 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// 7.1.1
int tongPhanTuTamGiacTren(int a[][100], int n) {
    int sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}


// 7.1.2
int TongPhanTuTamGiacDuoi(int a[][100], int n) {
    int sum=0;
    for (int i = 1; i < n; i++) {
        for (int j = 0 ; j < i; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
//7.1.3
int TongPhanTuTrenCheoChinh(int a[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }
    return sum;
}
//7.1.4
int TongPhanTuTrenCheoPhu(int a[][100], int n) {
    int sum = 0;
    for (int i = n-1; i >= 0; i--) {
        sum += a[i][n-i-1];
    }
    return sum;
}
//7.1.5
int TongPhanTuChanNamTrenBien(int a[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i==n-1 || j==0 || j==n-1) {
                if (a[i][j]%2 == 0) {
                    sum+=a[i][j];
                }
            }
        }
        
    }
    return sum;
}
int main() {
    int a[100][100];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    int sum = tongPhanTuTamGiacTren(a,n);
    printf("Tong cac phan tu thuoc ma tran tam giac tren nhung khong tinh duong cheo la: %d\n", sum);
    
    sum = TongPhanTuTamGiacDuoi(a,n);
    printf("Tong cac phan tu thuoc ma tran tam giac duoi nhung khong tinh duong cheo la: %d\n", sum);
    
    sum = TongPhanTuTrenCheoChinh(a,n);
    printf("Tong cac phan tu thuoc duong cheo chinh la: %d\n", sum);
    
    sum = TongPhanTuTrenCheoPhu(a,n);
    printf("Tong cac phan tu thuoc duong cheo phu la: %d\n", sum);
    
    sum = TongPhanTuChanNamTrenBien(a,n);
    printf("Tong cac phan tu chan thuoc bien la: %d\n", sum);

    return 0;
}   