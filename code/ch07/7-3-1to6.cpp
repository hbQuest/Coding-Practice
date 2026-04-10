#include <stdio.h>
#include <math.h>


void nhap(int a[][100], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > 100) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
// 7.3.1
int demCapGiaTriDoiXungQuaCheoChinh(int a[][100], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            printf("(%d,%d) ", a[i][j], a[j][i]);
            if (a[i][j] == a[j][i]) {
                dem++;
            }
        }
    }
    printf("\n");
    return dem;
}
// 7.3.2
int DemSoLuongDongGiam(int a[][100], int n) {
    int dem=0;
    for (int i = 0; i < n; i++) {
        bool dongGiam = true;
        for (int j = 1; j < n; j++) {
            if (a[i][j] > a[i][j-1]) {
                dongGiam = false;
                break;
            }
        }
        if (dongGiam) {
            dem++;
        }
    }
    return dem;
}
// 7.3.3
bool LaCucDai(int a[][100],int n, int dong, int cot) {
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};
    for (int i = 0; i < 8; i++) {
        if (dong+x[i] < n && dong+x[i]>=0 && cot+y[i] < n && cot+y[i] >= 0) {
            if (a[dong][cot] < a[dong+x[i]][cot+y[i]]) {
                return false;
            }
        }
    }
    return true;
}
int DemPhanTuCucDai(int a[][100], int n) {
    int dem = 0;
    if (n == 1) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0 ;j < n; j++) {
            if (LaCucDai(a,n,i,j)) {
                dem++;
            }
        }
    }
    return dem;
}
// 7.3.4
int DemGiaTriDuongTrenCheoChinh(int a[][100], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] > 0) {
            dem++;
        }
    }
    return dem;
}
// 7.3.5
int DemGiaTriAmTrenCheoPhu(int a[][100], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][n-i-1] < 0) {
            dem++;
        }
    }
    return dem;
}
// 7.3.6
int DemSoChanTrongTamGiacTren(int a[][100], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i][j]%2 == 0){
                dem++;
            }
        }
    }
    return dem;
}
int main() {
    int a[100][100];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    int dem = demCapGiaTriDoiXungQuaCheoChinh(a,n);
    printf("So cap gia tri doi xung qua duong cheo chinh la: %d\n", dem);    
    
    dem = DemSoLuongDongGiam(a,n);
    printf("So dong giam la: %d\n", dem);    
    
    dem = DemPhanTuCucDai(a,n);
    printf("So phan tu cuc dai la: %d\n", dem);    

    return 0;
}   