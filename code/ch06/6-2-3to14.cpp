#include <stdio.h>
#include <math.h>

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

// 6.2.3
int demX(int a[][100],int dong,int cot,int x) {
    if (dong <= 0 || cot <= 0) {
        return 0;
    }
    int dem=0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (x == a[i][j]) {
                dem++;
            }
        }
    }
    return dem;
}

// 6.2.4
void DemChuSoTrong1So(int a[], int n) {
    if (n == 0) {
        a[0]++;
        return;
    }
    n = abs(n);
    while (n != 0)
    {
        int donVi = n%10;
        a[donVi]++;
        n /= 10;
    }
}
void DemSoChuSoTrongMaTran(int a[][100], int dong, int cot) {
    int demChuSo[10] = {0};
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            DemChuSoTrong1So(demChuSo, a[i][j]);
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("So %d xuat hien %d lan\n", i, demChuSo[i]);
    }
}

// 6.2.6
bool KiemTraSoHoanThien(int n) {
    if (n <= 1) {return false;}
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n%i == 0) {
            sum += i;
        }
    }
    if (sum == n) return true;
    return false;
}

int DemSoLuongSoHoanThienTren1Hang(int a[][100], int dongCanDem, int cot) {
    int dem = 0;
    for (int i = 0; i < cot; i++) {
        if (KiemTraSoHoanThien(a[dongCanDem][i])) {
            dem++;
        }
    }
    return dem;
}

// 6.2.8
int DemSoLuongDuongTrenBien(int a[][100], int dong, int cot) {
    int dem = 0;
    // dem so duong dong dau va cuoi
    for (int i = 0; i < cot; i++) {
        if (a[0][i] > 0) {
            dem++;
        }
        if (dong > 1) {
            if (a[dong-1][i] > 0) {
                dem++;
            }       
        }
    }
    // dem so duong cot dau va cuoi tru so goc tren va duoi
    for (int i = 1; i < dong-1; i++) {
        if (a[i][0] > 0) {
            dem++;
        }
        if (cot > 1) {
            if (a[i][cot-1] > 0) {
                dem++;
            }
        }
    }
    return dem;
}

// 6.2.9
bool KiemTraCucDai(int a[][100], int dong, int cot, int d, int c) {
    // mang 1 chieu luu do lech toa do cua 8 phan tu xung quanh
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};

    for (int i = 0; i < 8; i++) {
        int dongi = d + x[i]; // dong cua phan tu xung quanh
        int cotj = c + y[i]; // cot cua phan tu xung quanh

        if (dongi >= 0 && dongi < dong && cotj >= 0 && cotj < cot) {
            if (a[d][c] <= a[dongi][cotj]) {
                return false;
            }
        }
    }
    return true;
}

int DemSoLuongPhanTuCucDai(int a[][100], int dong, int cot) {
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraCucDai(a,dong,cot,i,j)) {
                dem++;
                printf("%d \n", a[i][j]);
            }

        }
    }
    return dem;
}

// 6.2.10
bool KiemTraCucTri(int a[][100], int dong, int cot, int d, int c) {
    // mang 1 chieu luu do lech toa do cua 8 phan tu xung quanh
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};
    bool laCucDai = true, laCucTieu = true;

    for (int i = 0; i < 8; i++) {
        int dongi = d + x[i]; // dong cua phan tu xung quanh
        int cotj = c + y[i]; // cot cua phan tu xung quanh

        // kiem tra index hop le (nam trong ma tran)
        if (dongi >= 0 && dongi < dong && cotj >= 0 && cotj < cot) {
            if (a[d][c] <= a[dongi][cotj]) {
                laCucDai = false;
            }
            if (a[d][c] >= a[dongi][cotj]) {
                laCucTieu = false;
            }
            // Tối ưu: Nếu cả hai đều false thì không cần kiểm tra hàng xóm khác nữa
            if (!laCucDai && !laCucTieu) break;
        }
    }
    return (laCucDai || laCucTieu);
}

int DemSoLuongPhanTuCucTri(int a[][100], int dong, int cot) {
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraCucTri(a,dong,cot,i,j)) {
                dem++;
                printf("%d \n", a[i][j]);
            }

        }
    }
    return dem;
}

//  6.2.11: cach 2 la sap xep tang dan roi dem
int DemSoLuongGiaTriPhanBiet(int a[][100], int dong, int cot) {
    int dem = 0, n = dong*cot;
    for (int i  = 0; i < n; i++) {
        bool soMoi = true;
        for (int k = 0; k < i; k++) {
            if (a[k/cot][k%cot] == a[i/cot][i%cot]) {
                soMoi = false;
                break;
            }
        }
        if (soMoi) {
            dem++;
        }
    }
    return dem;
}

// 6.2.12
bool KiemTraPhanTuCucTri(int a[][100], int dong, int cot, int d, int c) {
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};
    bool cucDai = true, cucTieu = true;

    for (int k = 0; k < 8; k++) {
        int dongX = d + x[k];
        int cotX = c + y[k];

        if (dongX < dong && dongX >= 0 && cotX < cot && cotX >= 0) {
            if (a[d][c] <= a[dongX][cotX]) {
                cucDai = false;
            }
            if (a[d][c] >= a[dongX][cotX]) {
                cucTieu = false;
            }
        }
        if (!cucDai&&!cucTieu) {return false;}
    }
    return (cucDai||cucTieu);
}
int TinhTongPhanTuCucTri(int a[][100], int dong, int cot) {
    int sum = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraPhanTuCucTri(a,dong,cot,i,j)) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

// 6.2.13
bool KiemTraLaHoangHau(int a[][100], int dong, int cot, int d, int c) {
    // luu 8 huong can duyet vao mang 1 chieu
    int x[8] = {0,0,-1,1,-1,-1,1,1};
    int y[8] = {-1,1,0,0,-1,1,-1,1};

    for (int k = 0; k < 8; k++) {
        int dongMoi = d+ x[k];
        int cotMoi = c + y[k];

        while (dongMoi >= 0 && dongMoi < dong && cotMoi < cot && cotMoi >= 0) {
            if (a[dongMoi][cotMoi] >= a[d][c]) {
                return false;
            }
             
            // de duyet het huong do, tiep tuc them buoc nua khi dang theo 1 trong 8 huong 
            dongMoi += x[k];
            cotMoi += y[k];
        }
    }
    return true;
}

int DemSoLuongGiaTriHoangHau(int a[][100], int dong, int cot) {
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraLaHoangHau(a,dong,cot,i,j)) {
                dem++;
                printf("%d \n", a[i][j]);
            }

        }
    }
    return dem;
}

// 6.2.14
bool KiemTraLaYenNgua(int a[][100], int dong, int cot, int d, int c) {
    // kiem tra tren dong
    for (int i = 0; i < cot; i++) {
        if (i != c) {
            if (a[d][i] >= a[d][c]) {
                return false;
            }
        }
    }
    // kiem tra tren cot
    for (int i = 0; i < dong; i++) {
        if (i != d) {
            if (a[i][c] <= a[d][c]) {
                return false;
            }
        }
    }
    return true;
}
int DemSoLuongGiaTriYenNgua(int a[][100], int dong, int cot) {
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraLaYenNgua(a,dong,cot,i,j)) {
                dem++;
                printf("%d \n", a[i][j]);
            }

        }
    }
    return dem;
}

// 6.2.14
int DemSoLuongGiaTriYenNguaCach2(int a[][100], int dong, int cot) {
    int dem = 0;

    int maxDong[dong], minCot[cot];

    for (int i = 0; i < dong; i++) {
        maxDong[i] = a[i][0];
        for (int j = 1; j < cot; j++) {
            if (a[i][j] > maxDong[i]) {
                maxDong[i] = a[i][j];
            }
        }
    }

    for (int i = 0; i < cot; i++) {
        minCot[i] = a[0][i];
        for (int j = 1; j < dong; j++) {
            if (a[j][i] < minCot[i]) {
                minCot[i] = a[j][i];
            }
        }
    }

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] == maxDong[i] && a[i][j] == minCot[j]) {
                dem++;
                printf("%d \n", a[i][j]);
            }

        }
    }
    return dem;
}

int main() {
    int a[100][100];
    int dong, cot;
    nhap(a, dong, cot);
    xuat(a, dong, cot);

    // printf("Dem so chu so trong ma tran!\n");
    // DemSoChuSoTrongMaTran(a,dong,cot);

    // int hangCanDem = 1;
    // int d = DemSoLuongSoHoanThienTren1Hang(a,hangCanDem, cot);
    // printf("So luong so hoan thien tren hang %d la %d", hangCanDem, d);
    
    int r = DemSoLuongDuongTrenBien(a,dong,cot);
    printf("So luong so duong tren bien la %d\n", r);
    
    int d= DemSoLuongPhanTuCucDai(a,dong,cot);
    printf("So luong phan tu cuc dai la %d\n", d);
    
    d = DemSoLuongPhanTuCucTri(a,dong,cot);
    printf("So luong phan tu cuc tri la %d\n", d);

    d = DemSoLuongGiaTriPhanBiet(a,dong,cot);
    printf("So luong gia tri phan biet la %d\n", d);
    
    int s = TinhTongPhanTuCucTri(a,dong,cot);
    printf("Tong phan tu cuc tri la %d\n", s);

    d = DemSoLuongGiaTriHoangHau(a,dong,cot);
    printf("So luong gia tri hoang hau la %d\n", d);

    d = DemSoLuongGiaTriYenNguaCach2(a,dong,cot);
    printf("So luong gia tri yen ngua la %d\n", d);
    return 0;
}