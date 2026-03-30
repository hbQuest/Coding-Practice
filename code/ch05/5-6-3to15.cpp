#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int &n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

// 5.6.3
bool kiemTraDoiXung(int n) { 
    int soDao=0, donVi;
    int temp = n;
    while (temp != 0) {
        donVi = temp%10;
        soDao = soDao * 10 + donVi;
        temp /= 10;
    }
    if (soDao == n) {
        return true;
    }
    return false;
}
 
int demSoDoiXung(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraDoiXung(a[i])) {
            sum += a[i];
        }
    }
    return sum;
}

// 5.6.5
int kiemTraTanCungLa5(int n) {
    int donVi = n%10;
    if (abs(donVi) == 5) {
        return true;
    }
    return false;
}

int demSoTanCungLa5(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraTanCungLa5(a[i])) {
            dem++;
        }
    }
    return dem;
}

// 5.6.6
int tuongQuanSoLuongChanLe(int a[], int n) {
    int demChan=0, demLe=0;
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            demChan++;
        } else {
            demLe++;
        }
    }
    if (demChan > demLe) {
        return -1;
    } else if (demChan < demLe) {
        return 1;
    }
    return 0;
}

// 5.6.7
int demPhanTuLonHonHayNhoHonXungQuanh(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i+1] != a[i]) {
                dem++;
            }
        } else if (i == n-1){
            if (a[i-1] != a[i]) {
                dem++;
            }
        } else {
            if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) {
                dem++;
            }        
        }
    }
    return dem;
}

// 5.6.8
bool checkSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int demSoNguyenTo(int a[], int n) {
    int dem=0;
    for (int i = 0; i < n; i++) {
        if (checkSoNguyenTo(a[i])) {
            dem++;
        }
    }
    return dem;
}

// 5.6.9
bool checkSoHoanThien(int n) {
    if (n < 1) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n%i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    }
    return false;
}

int demSoHoanThien(int a[], int n) {
    int dem=0;
    for (int i = 0; i < n; i++) {
        if (checkSoHoanThien(a[i])) {
            dem++;
        }
    }
    return dem;
}

// 5.6.11
int demSoPhanTuKeNhauDeuChan(int a[], int n ){
    int dem=0;
    for (int i = 0; i < n-1; i++) {
        if (a[i]%2 == 0 && a[i+1]%2 == 0) {
            dem++;
        }
    }
    return dem;
}

//  5.6.12
int demSoPhanTuKeNhauTraiDau(int a[], int n) {
    int dem=0;
    for (int i = 0; i < n-1; i++) {
        if (a[i]*a[i+1] < 0) {
            dem++;
        }
    }
    return dem;
}

// 5.6.14
int demSoLuongGiaTriPhanBiet(int a[], int n) {
    int dem=0;
    for (int i = 0; i < n; i++) {
        bool trung = false;
        for (int j = 0; j < i; j++) {
           if (a[i] == a[j]) {
                trung = true;    
                break;
            } 
        }
        if (!trung) {
            dem++;
        }
    }
    return dem;
}

// 5.6.15
void TanSuatXuatHienCacGiaTri(int a[], int n) {
    for (int i = 0; i < n; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
           if (a[i] == a[j]) {
                soMoi = false;    
                break;
            } 
        }
        if (soMoi) {
            int k = 1;
            for (int j = i+1; j < n; j++) {
                if (a[i] == a[j]) {
                    k++;
                }
            }
            printf("So %d xuat hien %d lan\n", a[i], k);
        }
    }
}

int main() {
    int a[100];
    int n;

    nhapMang(a, n);
    printf("Mang A: ");
    xuatMang(a, n);

    int count = demSoDoiXung(a, n);
    printf("So so doi xung trong mang la: %d\n", count);
    
    count = demSoTanCungLa5(a,n);
    printf("So luong so co tan cung la 5 trong mang la: %d\n", count);

    count = tuongQuanSoLuongChanLe(a,n);
    if (count == -1) {
        printf("So chan nhieu hon so le\n");
    } else if (count == 1) {
        printf("So chan it hon so le\n");
    } else {
        printf("So chan bang so le\n");
    }

    TanSuatXuatHienCacGiaTri(a,n);
    return 0; 

}