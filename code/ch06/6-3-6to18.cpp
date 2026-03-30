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


// 6.3.5
bool KiemTraHangTangDan(int a[][100], int d, int cot) {
    for (int i = 1; i < cot; i++) {
        if (a[d][i] <= a[d][i-1]) {
            return false;
        }
    }
    return true;
}

// 6.3.6
bool kiemTraCotGiamDan(int a[][100],int dong, int c) {
    for (int i = 0; i < dong - 1; i++) {
        if (a[i][c] <= a[i+1][c])
            return false;
    }
    return true;
}

// 6.3.7: Lưu ý không phải giảm toàn bộ mảng => không đưa về mảng 1 chiều được
bool KiemTraMaTranGiamTheoDongVaCot(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0 ; j < cot; j++) {
            if (j + 1 < cot) {
                if (a[i][j] <= a[i][j+1]) {
                    return false;
                }
            }
            if (i + 1 < dong) {
                if (a[i][j] <= a[i+1][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// 6.3.8
void LietKeDongToanAm(int a[][100], int dong, int cot) {
    printf("Cac dong toan am:\n");
    for (int i = 0; i < dong; i++) {
        int mang[cot];
        bool toanAm = true;
        for (int j = 0 ; j < cot; j++) {
            if (a[i][j] >= 0) {
                toanAm = false;
                break;
            } else {
                mang[j] = a[i][j];
            }
        }
        if (toanAm) {
            for (int j = 0 ; j < cot; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// 6.3.9
void LietKeChiSoDongToanGiaTriChan(int a[][100], int dong, int cot) {
    printf("Cac chi so dong toan chan: ");
    for (int i = 0; i < dong; i++) {
        bool toanChan = true;
        for (int j = 0; j < cot; j++) {
            if (a[i][j]%2 != 0) {
                toanChan = false;
            }
        }
        if (toanChan) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 6.3.13
bool KiemTraChinhPhuong(int n) {
    if (n < 0) {
        return false;
    }
    int temp = sqrt(n);
    if (temp*temp == n) {
        return true;
    }
    return false;
}

void LietKeCacCotChuaSoChinhPhuong(int a[][100], int dong, int cot) {
    bool flag = false;
    printf("Cac cot co chua so chinh phuong: \n");
    for (int i = 0; i < cot; i++) {
        bool coSoChinhPhuong = false;
        for (int j = 0 ; j < dong; j++) {
            if (KiemTraChinhPhuong(a[j][i])) {
                coSoChinhPhuong = true;
            }
        }
        if (coSoChinhPhuong) {
            flag = true;
            for (int j = 0 ; j < dong; j++) {
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
    }
    if (!flag) {
        printf("Khong co cot thoa dieu kien\n");
    }
}

//6.3.14
void LietKeCacDongChuaAm0Duong(int a[][100], int dong, int cot) {
    bool flag = false;
    printf("Cac dong chua am, 0, va duong la:\n");
    for (int i = 0; i < dong; i++) {
        bool chuaAm = false, chua0= false, chuaDuong=false;
        for (int j = 0; j < cot; j++) {
            if (a[i][j] == 0) {
                chua0 = true;
            }
            if (a[i][j] > 0) {
                chuaDuong = true;
            }
            if (a[i][j] < 0) {
                chuaAm = true;
            }
        }
        if (chua0&&chuaAm&&chuaDuong) {
            flag = true;
            printf("Dong %d: ", i);
            for (int j = 0; j < cot; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    if (!flag) {
        printf("Khong co dong thoa dieu kien\n");
    }
}

// 6.3.17
bool KiemTraMaTranALaMaTranConCuaB(int a[][100], int b[][100], int dA, int cA, int dB, int cB) {
    if (dA > dB || cA > cB) {
        return false;
    }
    // Tối ưu hơn: nên chạy đến dòng và cột giới hạn mà A có thể nằm trong B
    for(int i = 0; i<=dB-dA;i++) {
        for (int j = 0; j<=cB-dA;j++) {
            if (b[i][j] == a[0][0]) {
                bool flag = true;
                for (int k = 0; k < dA; k++) {
                    for (int t = 0; t < cA; t++) {
                        if (a[k][t] != b[i+k][j+t]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) 
                        break;
                }
                if (flag) {
                    return true;
                }
            }
        }
    }
    return false;
}

// 6.3.18: Tach Kiem tra nằm dúng vị trí của mảng con thành hàm riêng
bool KiemTraNamDungViTri(int a[][100], int b[][100], int dong, int cot, int dA, int cA) {
    for (int k = 0; k < dA; k++) {
        for (int t = 0; t < cA; t++) {
            if (a[k][t] != b[dong+k][cot+t]) {
                return false; 
            }
        }
    }
    return true;
}

int DemSoLanMaTranALaMaTranConCuaB(int a[][100], int b[][100], int dA, int cA, int dB, int cB) {
    if (dA > dB || cA > cB) {
        return 0;
    }
    // Tối ưu hơn: nên chạy đến dòng và cột giới hạn mà A có thể nằm trong B
    int dem = 0;
    for(int i = 0; i<=dB-dA;i++) {
        for (int j = 0; j<=cB-dA;j++) {
            if (b[i][j] == a[0][0]) {
                if (KiemTraNamDungViTri(a,b,i,j,dA,cA)) {
                    dem++;
                }
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

    // int c;
    // do {
    //     printf("Nhap cot muon kiem tra: ");
    //     scanf("%d", &c);
    //     if (c < 0 || c > cot) {
    //         printf("So cot khong hop le! Xin nhap lai!");
    //     }
    // } while (c < 0 || c > cot);

    // if (kiemTraCotGiamDan(a,dong,c)) {
    //     printf("Cot %d trong ma tran giam dan\n", c);
    // } else {
    //     printf("Cot %d trong ma tran KHONG giam dan\n", c);
    // }

    // LietKeDongToanAm(a,dong,cot);
    // LietKeChiSoDongToanGiaTriChan(a,dong,cot);
    // LietKeCacCotChuaSoChinhPhuong(a,dong,cot);
    // LietKeCacDongChuaAm0Duong(a,dong,cot);

    int b[100][100], db, cb;
    nhap(b, db, cb);
    xuat(b, db, cb);

    bool r = KiemTraMaTranALaMaTranConCuaB(a,b,dong,cot,db,cb);
    if (r) {
        printf("Mang A la mang con cua Mang b\n");
    } else {
        printf("Mang A KHONG la mang con cua Mang b\n");
    }

    int d = DemSoLanMaTranALaMaTranConCuaB(a,b,dong,cot,db,cb);
    printf("So lan mang con A nam trong B: %d\n", d);
    return 0;
}
