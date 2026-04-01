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

void lietKeMangCon(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
}

// 5.11.2
void lietKeMangConLonHon2PhanTu(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+2; j < n; j++) {
            for (int k = i; k <= j; k++) {
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
}

// 5.11.3
void LietKeDayConTangDan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            bool tangDan = true;
            for (int k = i; k < j; k++) {
                if (a[k] > a[k+1]) {
                    tangDan = false;
                    break;
                }
            }
            if (tangDan) {
                for (int k = i; k <= j; k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
        }
    }
}

// 5.11.3 Cach 2
void LietKeDayConTangDanCach2(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] > a[j-1]) {
                for (int k = i; k <= j; k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            } else {
                break; // neu da khong tang ngay tu dau thi moi phan sau nay khong con can phai xem xet
            }
        }
    }
}

// 5.11.4
void LietKeDayConTangVaChuaMax(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) { 
            max = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] <= a[j-1]) { // neu so hien tai nho hon so truoc do thi day hong phai mang tang dan, break
                break;
            }
            if(a[j] == max) { // chi can xem so cuoi cung mang con la max hay khong thi do la mang dung theo yeu cau
                for (int k = i; k <= j; k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
        }
    }
}

// 5.11.4
void TinhTongMangConTang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] <= a[j-1]) { 
                break;
            } else { 
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += a[k];
                    printf("%d ", a[k]);
                }
                printf(" - Tong %d\n", sum);
            }
        }
    }
}

// 5.11.5
int DemMangConTangDoDaiLonHon1(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] <= a[j-1]) { 
                break;
            } else { 
                dem++;
            }
        }
    }
    return dem;
}

// 5.11.7
void LietKeDayConToanDuongDoDaiHon1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) {
            continue;;
        }
        for (int j = i+1; j < n; j++) {
            if (a[j] <= 0) { 
                break;
            } else { 
                for (int k = i; k <= j ;k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
        }
    }
}

// 5.11.8
int DemMangConGiam(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] >= a[j-1]) {
                break;
            } else {
                dem++;
            }
        }
    }
    return dem;
}

// 5.11.9
bool MangALaMangConMangB(int a[], int b[], int n, int m) {
    if (n > m) return false;
    for (int i = 0; i < m; i++) {
        if (b[i] == a[0]) {
            bool laMangCon = true;
            for (int j = 0; j < n; j++) {
                if (a[j] != b[i+j]) {
                    laMangCon = false;
                    break;
                }
            }
            if (laMangCon) return true;
        }
    }
    return false;
}

// 5.11.10
int  DemSoLanMangAXuatHienTrongMangB(int a[], int b[], int n, int m) {
    if (n > m) return 0;
    int dem=0;
    for (int i = 0; i < m; i++) {
        if (b[i] == a[0]) {
            bool laMangCon = true;
            for (int j = 0; j < n; j++) {
                if (a[j] != b[i+j]) {
                    laMangCon = false;
                    break;
                }
            }
            if (laMangCon) {
                dem++;
            }
        }
    }
    return dem;
}

// 5.11.11
void  TimDayConToanDuongDaiNhat(int a[], int n) {
    int day[n];
    int maxChieuDai = 0;
    int chieuDaiHienTai = 0;
    int batDau = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            chieuDaiHienTai++;
            if (chieuDaiHienTai > maxChieuDai) {
                maxChieuDai = chieuDaiHienTai;
                batDau = i - maxChieuDai + 1;
            }
        } else {
            chieuDaiHienTai = 0;
        }
        
    }

    if (maxChieuDai == 0) {
        printf("Khong co day con toan duong\n");
    } else {
        printf("Day con toan duong dai nhat la: ");
        for (int i = batDau; i < maxChieuDai+batDau; i++) {
            printf("%d ", day[i]);
        }
    }
    printf("\n");
}

// 5.11.11 Cach 2
void  TimDayConToanDuongDaiNhatCach2(int a[], int n) {
    int maxChieuDai = 0, danhDau = 0;
    int i = 0;
    while (i < n) {
        if (a[i] > 0) {
            int batdau = i;
            int chieuDai = 0;
            while (i < n && a[i] > 0) {
                chieuDai++;
                i++;
            }
            if (maxChieuDai < chieuDai) {
                maxChieuDai = chieuDai;
                danhDau = batdau;
            }
        } else {
            i++;
        }
    }
    if (maxChieuDai > 0) {
        printf("Day con toan duong dai nhat la: ");
        for (int i = danhDau; i < danhDau + maxChieuDai; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        printf("Mang khong co day con toan duong\n");
    }
}

// 5.11.12
void TimMangConCoTongBangM(int a[], int n, int m) {
    printf("Mang con co tong = %d la:\n", m);
    for (int i = 0; i<n ; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == m) {
                for (int k = i; k <= j ; k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
        }
    }
}

// 5.11.13
void DayConToanDuongCoTongLonNhat(int a[], int n) {
    int max = 0, danhDau = 0, demMax = 0;
    int i = 0;
    while (i < n) {
        if (a[i] > 0) {
            int batdau = i;
            int sum = 0;
            int dem = 0;
            while (i < n && a[i] > 0) {
                sum += a[i];
                dem++;
                i++;
            }

            if (sum > max) {
                max = sum;
                danhDau = batdau;
                demMax = dem;
            }
        } else {
            i++;
        }
    }
    if (max > 0) {
        printf("Day con toan duong co tong lon nhat = %d la: ", max);
        for (int i = danhDau; i < demMax+danhDau; i++) {
            printf("%d ", a[i]);
        }
    } else {
        printf("Mang khong co day toan duong");
    }
    printf("\n");
}

// 5.11.14: cach giai chuan
void MangConCoTongLonNhat(int a[], int n) {
    int sumMax = a[0];
    int maxHienTai = a[0];
    int batDau = 0, ketThuc = 0;
    int batDauTam = 0;

    for (int  i = 0; i < n; i++) {
        if (a[i] > maxHienTai + a[i]) {
            batDauTam = i;
            maxHienTai = a[i];
        } else {
            maxHienTai += a[i];
        }

        if (maxHienTai > sumMax) {
            sumMax = maxHienTai;
            batDau = batDauTam;
            ketThuc = i;
        }
    }

    printf("Mang con co tong lon nhat = %d la: ", sumMax);
    for (int i = batDau; i <=ketThuc; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int a[100];

    NhapMang(a, n);
    XuatMang(a, n);

    printf("Liet ke mang con:\n");
    lietKeMangCon(a, n);

    // printf("Liet ke mang con nhieu hon 2 phan tu:\n");
    // lietKeMangConLonHon2PhanTu(a, n);
    
    printf("Liet ke mang con tang dan:\n");
    LietKeDayConTangDanCach2(a,n);
    
    // printf("Liet ke mang con tang dan va co chua max:\n");
    // LietKeDayConTangVaChuaMax(a,n);
    
    // printf("Tong tung mang con tang:\n");
    // TinhTongMangConTang(a,n);
    
    // int dem = DemMangConTangDoDaiLonHon1(a,n);
    // printf("So mang con tang co do dai lon hon 1: %d\n", dem);
    
    // printf("Mang con toan duong va do dai lon hon 1:\n");
    // LietKeDayConToanDuongDoDaiHon1(a,n);

    // int dem = DemMangConGiam(a,n);
    // printf("So mang con giam: %d\n", dem);


    // int b[100], m;
    // NhapMang(b,m);
    // XuatMang(b,m);
    // bool ketQua = MangALaMangConMangB(a,b,n,m);
    // if (ketQua) {
    //     printf("Mang a la mang con cua mang b\n");
    // } else {
    //     printf("Mang a khong la mang con cua mang b\n");
    // }

    // dem  = DemSoLanMangAXuatHienTrongMangB(a,b,n,m);
    // printf("So lan mang a xuat hien trong mang b: %d\n", dem);

    int m = 13;
    TimDayConToanDuongDaiNhat(a,n);
    TimMangConCoTongBangM(a,n,m);
    DayConToanDuongCoTongLonNhat(a,n);
    MangConCoTongLonNhat(a,n);
    return 0;
}