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

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// 6.6.1
void sapXepTangDan1Dong(int a[][100],int dong,int cot, int d) {
    for (int j = 0; j < cot-1; j++) {
        for (int k = j+1; k < cot; k++) {
            if (a[d][j] > a[d][k]) {
                hoanVi(a[d][j], a[d][k]);
            }
        }
    }
}
// 6.6.2
void sapXepGiamDan1Dong(int a[][100],int dong,int cot, int d) {
    for (int j = 0; j < cot-1; j++) {
        for (int k = j+1; k < cot; k++) {
            if (a[d][j] < a[d][k]) {
                hoanVi(a[d][j], a[d][k]);
            }
        }
    }
}

// 6.6.3
void SapXep1CotTangDan(int a[][100], int dong, int cot, int c) {
    for (int i = 0; i < dong-1; i++) {
        for (int j = i+1; j < dong; j++) {
            if (a[i][c] > a[j][c]) {
                hoanVi(a[i][c], a[j][c]);
            }
        }
    }
}
//6.6.4
void SapXep1CotGiamDan(int a[][100], int dong, int cot, int c) {
    for (int i = 0; i < dong-1; i++) {
        for (int j = i+1; j < dong; j++) {
            if (a[i][c] < a[j][c]) {
                hoanVi(a[i][c], a[j][c]);
            }
        }
    }
}
// 6.6.5
void XuatGiaTriChanGiamDan(int a[][100], int dong, int cot) {
    int mangChan[100];
    int dem=0;
    bool coChan = false;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j]%2 == 0) {
                if (!coChan) {
                    coChan = true;
                    mangChan[dem++] = a[i][j];
                } else {
                    int k = dem;
                    while (k > 0 && mangChan[k-1] < a[i][j]) {
                        mangChan[k] = mangChan[k-1];
                        k--;
                    }
                    mangChan[k] = a[i][j];
                    dem++;
                }
            }
        }
    }
    if (!coChan) {
        printf("Khong co so chan trong ma tran\n");
    } else {
        printf("Mang chan giam dan:\n");
        for(int i = 0; i < dem; i++) {
            printf("%d ", mangChan[i]);
        }
        printf("\n");
    }
}

// 6.6.6
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

void XuatSoNguyenToTangDan(int a[][100], int dong, int cot) {
    int mangNguyenTo[100];
    int dem=0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (KiemTraNguyenTo(a[i][j])) {
                mangNguyenTo[dem++] = a[i][j];
            }
        }
    } 
    if (dem == 0) {
        printf("Ma tran khong co so nguyen to\n");
    } else {
        for (int i = 0; i < dem-1; i++) {
            for (int j=i+1; j < dem; j++) {
                if (mangNguyenTo[j] < mangNguyenTo[i]) {
                    hoanVi(mangNguyenTo[j], mangNguyenTo[i]);
                }
            }
        }


        printf("So nguyen to theo thu tu tang dan:\n");
        for (int i = 0; i < dem; i++) {
            printf("%d ", mangNguyenTo[i]);
        }
        printf("\n");
    }
}

// 6.6.7
void SapXepDongChanTangDongLeGiam(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        if (i%2 == 0) {
            for (int j = 0; j < cot-1; j++) {
                for (int k = j+1; k < cot; k++) {
                    if (a[i][j] > a[i][k]) {
                        hoanVi(a[i][j],a[i][k]);
                    }
                }
            }
        } else {
            for (int j = 0; j < cot-1; j++) {
                for (int k = j+1; k < cot; k++) {
                    if (a[i][j] < a[i][k]) {
                        hoanVi(a[i][j],a[i][k]);
                    }
                }
            }
        }
    }
}

// 6.6.9
void SapXepTangDanTheoHangVaCot(int a[][100], int dong, int cot) {
    int n = dong*cot;
    int mangPhu[n];
    int dem = 0;

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            mangPhu[dem++] = a[i][j];
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (mangPhu[i] > mangPhu[j]) {
                hoanVi(mangPhu[i], mangPhu[j]);
            }
        }
    }
    dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = mangPhu[dem++];
        }
    }
}

// 6.6.9: không dùng mảng phụ
void SapXepTangDanTheoHangVaCotCach2(int a[][100], int dong, int cot) {
    int n = dong*cot;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i/cot][i%cot] > a[j/cot][j%cot]) {
                hoanVi(a[i/cot][i%cot], a[j/cot][j%cot]);
            }
        }
    }
}

// 6.6.12
void SapXepAmTangDuongGiam0GiuNguyen(int a[][100], int dong, int cot) {
    int n = dong*cot;
    for (int i = 0; i < n-1; i++) {
        int d1 = i/cot;
        int c1 = i%cot;
        int n1 = a[d1][c1];

        if (n1 == 0) { 
            continue;
        }

        for (int j = i+1; j < n; j++) {
            int d2 = j / cot;
            int c2 = j%cot;
            int n2 = a[d2][c2];
            if (n1 > 0 && n2 > 0) {
                if (a[d1][c1] < a[d2][c2]) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            } else if (n1 < 0 && n2 < 0) {
                if (a[d1][c1] > a[d2][c2]) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            }
        }
    }
}


// 6.6.13
void SapXepChanTangLeGiam(int a[][100], int dong, int cot) {
    int n = dong*cot;

    for (int i = 0; i < n-1; i++) {
        int d1 = i/cot;
        int c1 = i%cot;
        
        for (int j = i+1; j < n; j++) {
            int d2 = j/cot;
            int c2 = j%cot;
            if (a[d1][c1]%2 == 0 && a[d2][c2]%2 == 0) {
                if (a[d1][c1] > a[d2][c2]) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            } else if (a[d1][c1]%2 != 0 && a[d2][c2]%2 != 0) {
                if (a[d1][c1] < a[d2][c2]) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            }
        }
        
    }
}

// 6.6.14
void SapXepBienTangDan(int a[][100], int dong, int cot) {
    int b[100];
    int dem = 0;
    for (int i = 0; i < cot; i++) {
        b[dem++] = a[0][i];
    }
    for (int i = 1; i < dong; i++) {
        b[dem++] = a[i][cot-1];
    }
    if (dong > 1) { // tránh trùng lại nếu dòng chỉ 1
        for (int i = cot-2; i >= 0; i--) {
            b[dem++] = a[dong-1][i];
        }
    }
    if (cot > 1) { // tránh trùng lại nếu cột chỉ 1
        for (int i = dong-2; i > 0; i--) {
            b[dem++] = a[i][0];
        }
    }
    
    // Sắp xếp mảng phụ chứa phần tử biên
    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
    // trả lại mảng phụ cho a
    dem = 0;
    for (int i = 0; i < cot; i++) {
        a[0][i] = b[dem++];
    }
    for (int i = 1; i < dong; i++) {
        a[i][cot-1] = b[dem++];
    }
    if (dong > 1) { 
        for (int i = cot-2; i >= 0; i--) {
            a[dong-1][i] = b[dem++];
        }
    }
    if (cot > 1) { 
        for (int i = dong-2; i > 0; i--) {
            a[i][0] = b[dem++];
        }
    }
}

// 6.6.16
void SapXepTheoTongCacDongTangDan(int a[][100], int dong, int cot) {
    int b[dong];
    int dem = 0;
    for (int i =0;i<dong;i++) {
        int sum = 0;
        for (int j = 0; j <cot; j++) {
            sum += a[i][j];
        }
        b[dem++] = sum;
    }

    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[j] < b[i]) {
                hoanVi(b[i], b[j]);
                for (int k = 0 ; k < cot; k++) {
                    hoanVi(a[i][k], a[j][k]);
                }
            }
        }
    }
}

// 6.6.17
void SapXepTangDanTheoDangXoanOc(int a[][100], int dong, int cot) {
    int n = dong*cot;
    int b[n], dem=0;

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[dem++] = a[i][j];
        }
    }

    for (int i= 0 ; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[j] < b[i]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
    dem = 0;
    int tren = 0, duoi = dong-1, trai = 0, phai = cot-1;
    while (dem < n) {
        // Phải kiểm tra mỗi vòng for dem < n?
        for (int i = trai; i <= phai && dem < n; i++) {
            a[tren][i] = b[dem++];
        }
        tren++;
        for (int j = tren; j <= duoi && dem < n; j++) {
            a[j][phai] = b[dem++];
        }
        phai--;
        for (int k = phai; k >= trai && dem < n; k--) {
            a[duoi][k] = b[dem++];
        }
        duoi--;
        for (int t = duoi; t >= tren && dem < n; t--) {
            a[t][trai] = b[dem++];
        }
        trai++;
    }
}
// 6.6.18
void SapXepTangDanTheoZiczac(int a[][100], int dong, int cot) {
    int n = dong*cot;
    int b[n], dem=0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[dem++] = a[i][j];
        }
    }

    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[j] < b[i]) {
                hoanVi(b[i], b[j]);
            }
        }
    }

    dem = 0;
    
    for (int i = 0; i < dong; i++) {
        if (i%2 == 0) {
            for (int j = 0 ; j < cot; j++) {
                a[i][j] = b[dem++];
            }
        } else {
            for (int j = cot-1 ; j >= 0; j--) {
                a[i][j] = b[dem++];
            }
        }
    }
}

// 6.6.19
void XuatGiaTriAmGiamDan(int a[][100], int dong, int cot) {
    int n = dong*cot;
    for (int i = 0; i < n-1; i++) {
        int d1 = i/cot;
        int c1 = i%cot;
        if (a[d1][c1] < 0) {
            for (int j = i+1; j < n; j++) {
                int d2 = j/cot;
                int c2 = j%cot;
                if (a[d2][c2] < 0 && a[d2][c2] > a[d1][c1]) {
                    hoanVi(a[d2][c2], a[d1][c1]);
                }
            }
        }
    }
}

int main() {
    int a[100][100];
    int dong, cot, d;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    // do {
    //     printf("Nhap dong muon xep giam dan: ");
    //     scanf("%d", &d);
    //     if (d < 0 || d >= dong) {
    //         printf("Dong hong hop le! Xin nhap lai\n");
    //     }
    // } while (d < 0 || d >= dong);
    
    // printf("Ma tran sau khi sap xep dong %d giam dan:\n", d);
    // sapXepGiamDan1Dong(a,dong,cot,d);
    // xuat(a, dong, cot);

    // do {
    //     printf("Nhap dong muon xep tang dan: ");
    //     scanf("%d", &d);
    //     if (d < 0 || d >= dong) {
    //         printf("Dong hong hop le! Xin nhap lai\n");
    //     }
    // } while (d < 0 || d >= dong);
    
    // printf("Ma tran sau khi sap xep dong %d tang dan:\n", d);
    // sapXepTangDan1Dong(a,dong,cot,d);
    // xuat(a, dong, cot);
    
    // int c;
    // do {
    //     printf("Nhap cot muon xep tang dan: ");
    //     scanf("%d", &c);
    //     if (c < 0 || c >= cot) {
    //         printf("Cot hong hop le! Xin nhap lai\n");
    //     }
    // } while (c < 0 || c >= cot);
    
    // printf("Ma tran sau khi sap xep cot %d tang dan:\n", c);
    // SapXep1CotTangDan(a,dong,cot,c);
    // xuat(a, dong, cot);

    // XuatGiaTriChanGiamDan(a,dong,cot);

    // XuatSoNguyenToTangDan(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep dong chan tang dan, dong le giam dan:\n");
    // SapXepDongChanTangDongLeGiam(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep tang dan theo hang va cot:\n");
    // SapXepTangDanTheoHangVaCotCach2(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep duong giam dan, am tang dan, 0 giu nguyen:\n");
    // SapXepAmTangDuongGiam0GiuNguyen(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep chan tang le giam:\n");
    // SapXepChanTangLeGiam(a,dong,cot);
    // xuat(a,dong,cot);
    
    
    // printf("Ma tran sau khi sap xep bien tang dan:\n");
    // SapXepBienTangDan(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep theo dong co tong tang dan:\n");
    // SapXepTheoTongCacDongTangDan(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep tang dan theo ziczac:\n");
    // SapXepTangDanTheoZiczac(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Ma tran sau khi sap xep tang dan theo xoan oc:\n");
    // SapXepTangDanTheoDangXoanOc(a,dong,cot);
    // xuat(a,dong,cot);

    XuatGiaTriAmGiamDan(a,dong,cot);
    xuat(a,dong,cot);


    return 0;
}