#include <stdio.h>

void nhap(int a[][100], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 1 || dong > 100) {
            printf("So dong khong hop le! Xin nhap lai!");
        }
    } while(dong < 1 || dong > 100);
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 1 || cot > 100) {
            printf("So cot khong hop le! Xin nhap lai!");
        }
    } while(cot < 1 || cot > 100);
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

// 6.0.3
int TimMax(int a[][100],int dong,int cot) {
    int max = a[0][0]; 
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// 6.0.3
bool TimGiaTriChanNhoHon2004(int a[][100],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j]%2 == 0 && a[i][j] < 2004) {
                return true;
            }
        }
    }
    return false;
}

// 6.0.5
bool checkSoNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n < 2 || n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i = 5; i*i < n; i+=6) {
        if (n%i == 0 | n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

double TrungBinhCacSoNguyenTo(int a[][100],int dong,int cot) {
    int count = 0, s = 0;
    bool flag = false;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (checkSoNguyenTo(a[i][j])) {
                s += a[i][j];
                count++;
                flag = true;
            }
        }
    }
    if (flag) {
        return (double)s/count;
    }
    return -1.0;
}

// 6.0.6
int TongCacGiaTriAm(int a[][100], int dong, int cot) {
    int n = dong*cot;
    int sum = 0;
    for (int i = 0; i <n-1; i++) {
        if (a[i/cot][i%cot] < 0) {
            sum += a[i/cot][i%cot];
        }
    }
    return sum;
}

// 6.0.7
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void SapXepTangDan(int a[][100],int dong,int cot) {
    int n = dong*cot;
    int temp[n];
    int index = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            temp[index] = a[i][j];
            index++;
        }
    }
    // Sap xep mang 1 chieu
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (temp[i] > temp[j]) {
                swap(temp[i], temp[j]);
            }
        }
    }
    // Tra lai cho mang ban dau
    index = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = temp[index];
            index++;
        }
    }
}

// cach 2
void SapXepTangDanCach2(int a[][100], int dong, int cot) {
    int n = dong*cot;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j/cot][j%cot] < a[i/cot][i%cot]) {
                swap(a[j/cot][j%cot], a[i/cot][i%cot]);
            }
        }
    }
}
int main() {
    int a[100][100], dong, cot;
    nhap(a, dong, cot);
    xuat(a, dong, cot);

    double r = TrungBinhCacSoNguyenTo(a,dong,cot);
    if (r < 0) {
        printf("Khong co so nguyen to trong ma tran\n");
    } else {
        printf("%.2lf\n", r);
    }

    SapXepTangDanCach2(a,dong,cot);
    xuat(a,dong,cot);

    int sum = TongCacGiaTriAm(a,dong,cot);
    printf("Tong cac gia tri am la %d", sum);
    return 0;
}