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
// 7.2.1
int TimMaxTamGiacTren(int a[][100], int n) {
    if (n <= 1) {return 0;}
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}
// 7.2.2
int TimMinTamGiacDuoi(int a[][100], int n) {
    if (n <= 1) {return 0;}
    int min = a[1][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0 ; j < i; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    return min;
}
// 7.2.3
int TimMaxTrenCheoChinh(int a[][100], int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] > max) {
            max = a[i][i];
        }
    }
    return max;
}
// 7.2.4
int TimMaxTrenCheoPhu(int a[][100], int n) {
    int max = a[0][n-1];
    for (int i = 0; i < n; i++) {
        if (a[i][n-1-i] > max) {
            max = a[i][n-1-i];
        }
    }
    return max;
}
// 7.2.5 
bool KiemTraNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n < 2 || n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i = 5 ; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

int TimMaxNguyenTo(int a[][100], int n) {
    int max;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (KiemTraNguyenTo(a[i][j])) {
                if(!flag || a[i][j] > max) {
                    max = a[i][j];
                    flag = true;
                }
            }
        }
    }
    if (flag) {
        return max;
    } else {
        return -1;
    }
}
// 7.2.6
void Tim2GiaTriGanNhauNhat(int a[][100], int n) {
    if (n <= 1) {
        printf("Ma tran khong du 2 gia tri de tim\n");
        return;
    }
    int minDistance = abs(a[0][0]- a[0][1]);
    int n1 = a[0][0], n2=a[0][1];
    int x = n*n;
    for (int i = 0 ; i < x-1; i++) {
        for (int j = i+1; j < x; j++) {
            if (abs(a[i/n][i%n] - a[j/n][j%n]) < minDistance) {
                minDistance = abs(a[i/n][i%n] - a[j/n][j%n]);
                n1 = a[i/n][i%n];
                n2 = a[j/n][j%n];
            }
        }
    }
    printf("2 gia tri gan nhau nhat la: %d va %d\n", n1, n2);
}

// 7.2.7
int TinhTongMaTranVuong(int a[][100], int tren, int duoi, int trai, int phai) {
    int sum = 0;
    for (int i = tren; i <= duoi; i++) {
        for (int j = trai; j <= phai; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
void TimMaTranVuongMax(int a[][100], int b[][100], int n, int &nB) {
    int trenM = 0, duoiM = 0, traiM = 0, phaiM = 0;
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        int tren = i;
        for (int j = 0; j < n; j++) {
            int trai = j;
            int sum;
            int k = 0;
            while (k < n-j && k < n-i) {
                int phai = trai + k;
                int duoi = tren + k;
                sum = TinhTongMaTranVuong(a,tren,duoi,trai,phai);
                if (sum > max) {
                    max = sum;
                    trenM = tren;
                    duoiM = duoi;
                    traiM = trai;
                    phaiM = phai;
                }
                k++;
            }
        }
    }
    nB = duoiM-trenM+1;
    for (int i = 0; i < nB; i++) {
        for (int j = 0; j < nB; j++) {
            b[i][j] = a[trenM+i][traiM+j];
        }
    }
}
int main() {
    int a[100][100];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    int max = TimMaxTamGiacTren(a,n);
    printf("Max trong ma tran tam giac tren la: %d\n", max);

    int min = TimMinTamGiacDuoi(a,n);
    printf("Min trong ma tran tam giac duoi la: %d\n", min);
    
    max = TimMaxTrenCheoChinh(a,n);
    printf("Max tren duong cheo chinh la: %d\n", max);
    
    max = TimMaxTrenCheoPhu(a,n);
    printf("Max tren duong cheo phu la: %d\n", max);
    
    max = TimMaxNguyenTo(a,n);
    if (max != -1) {
        printf("Max so nguyen to trong ma tran la: %d\n", max);
    } else {
        printf("Ma tran khong co so nguyen to\n");
    }

    Tim2GiaTriGanNhauNhat(a,n);

    int b[100][100];
    int nB;
    printf("Max ma tran vuong B trong ma tran A!\n");
    TimMaTranVuongMax(a,b,n,nB);
    xuat(b,nB);


    return 0;
}   
