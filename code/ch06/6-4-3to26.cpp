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

// 6.4.3
int timMax2(int a[][100],int dong,int cot) {
    // Hoac dung phuong phap toi uu hon: dat max = min = INT_MIN
    // include <limits.h>

    int max = a[0][0], min = a[0][0];
    for (int  i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    int max2 = min;
    for (int  i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] > max) {
                max2 = max;
                max = a[i][j];
            } else if (a[i][j] > max2 && a[i][j] < max) {
                max2 = a[i][j];
            }
        }
    }
    return max2;    
}

// 6.4.3
int timMax2Cach2(int a[][100],int dong,int cot) {
    int max = a[0][0];
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    int max2;
    bool coMax2 = false;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] < max) {
                if (!coMax2) {
                    max2 = a[i][j];
                    coMax2 = true;
                } else {
                    if (a[i][j] > max2) {
                        max2 = a[i][j];
                    }
                }
            }
        }
    }
    return max2;
}

// 6.4.5
int TimGiaTriAmLonNhat(int a[][100], int dong, int cot) {
    int maxAm;
    bool coAm = false;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] < 0) {
                if (!coAm || a[i][j] > maxAm) {
                    maxAm = a[i][j];
                    coAm = true;
                }
            }
        }
    }
    if (coAm) {
        return maxAm;
    }
    return 0;
}

// 6.4.6
void LietKeDongChuaMax(int a[][100], int dong, int cot) {
    int max = a[0][0];
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    for (int i=0;i<dong;i++) {
        bool coMax = false;
        for (int j=0;j<cot;j++) {
            if (a[i][j] == max) {
                coMax = true;
                break;
            }
        }
        if (coMax) {
            printf("Dong %d chua max = %d: ", i, max);
            for(int k = 0; k < cot; k++) {
                printf("%d ", a[i][k]);
            }
            printf("\n");
        }
    }
}

// 6.4.7
void GiaTriLonNhatTren1Dong(int a[][100], int dong, int cot) {
    for (int i=0;i<dong;i++) {
        int maxDong = a[i][0];
        for (int j=0;j<cot;j++) {
            if (a[i][j] > maxDong) {
                maxDong = a[i][j];
            }
        }
        printf("Gia tri lon nhat dong %d: %d\n", i, maxDong);
    }
}

// 6.4.8
int TimGiaTriNhoNhatTren1Cot(int a[][100], int dong, int c) {
    int minCot = a[0][c];
    for (int i=1;i<dong;i++) {
        if (a[i][c] < minCot) {
            minCot = a[i][c];
        }
    }
    return minCot;
}


// 6.4.10
int TimSoChanLonNhat(int a[][100], int dong, int cot) {
    bool coChan = false;
    int maxChan;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j]%2 == 0) {
                if (!coChan || a[i][j] > maxChan) {
                    maxChan = a[i][j];
                    coChan = true;
                }
            }
        }
    }
    if (coChan) {
        return maxChan;
    }
    return -1;
}


// 6.4.13
void DemChuSoXuatHien(int a[], int n) {
    n = abs(n);
    while (n!=0) {
        int donVi = n%10;
        a[donVi]++;
        n /= 10;
    }
}

// 6.4.13
int TimChuSoXuatHienNhieuNhat(int a[][100], int dong, int cot) {
    int demChuSo[10] = {0};
    // Đếm tần suất các chữ số xuất hiện rồi gán cho mảng 1 chiều
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] == 0) {
                demChuSo[0]++;
            } else {
                DemChuSoXuatHien(demChuSo, a[i][j]);
            }
        }
    }
    // tìm chữ số có số đếm xuất hiện nhiều nhất
    int chuSoMax = 0;
    for (int i = 1; i < 10; i++) {
        if (demChuSo[i] > demChuSo[chuSoMax]) {
            chuSoMax = i;
        }
    }
    return chuSoMax;
}

// 6.4.14
int DemSoLanXuatHienCuaSoNhoNhat(int a[][100], int dong, int cot) {
    int min = a[0][0];
    int dem = 0;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] < min) {
                dem = 1;
                min = a[i][j];
            } else if (a[i][j] == min) {
                dem++;
            }
        }
    }
    printf("%d\n", min);
    return dem;
}

// 6.4.15
int DemSoLuongChanNhoNhat(int a[][100], int dong, int cot) {
    int minChan;
    int dem = 0;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j]%2 == 0) {
                if (dem == 0 || a[i][j] < minChan) {
                    minChan = a[i][j];
                    dem = 1;
                } else if (a[i][j] == minChan) {
                    dem++;
                }
            }
        }
    }
    printf("%d\n", minChan);
    return dem;
}

// 6.4.16
int TimGiaTriXuatHienNhieuNhat(int a[][100], int dong, int cot) {
    int soXuatHienNhieuNhat = a[0][0];
    int demMax = 1;
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            int dem = 0;
            for (int k=0;k<dong;k++) {
                for (int t=0;t<cot;t++) {
                    if (a[k][t] == a[i][j]) {
                        dem++;
                    }
                }
            }
            if (dem > demMax) {
                demMax = dem;
                soXuatHienNhieuNhat = a[i][j];
            }
        }
    }
    return soXuatHienNhieuNhat;
}

// 6.4.19: Liệt kê các chữ số xuất hiện nhiều nhất
void LietKeCacChuSoXuatHienNhieuNhat(int a[][100], int dong, int cot) {
    int demChuSo[10] = {0};
    // Đếm tần suất các chữ số xuất hiện rồi gán cho mảng 1 chiều
    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            if (a[i][j] == 0) {
                demChuSo[0]++;
            } else {
                DemChuSoXuatHien(demChuSo, a[i][j]);
            }
        }
    }
    // tìm chữ số xuất hiện nhiều nhất
    int demMax = demChuSo[0];
    for (int i = 1; i < 10; i++) {
        if (demChuSo[i] > demMax) {
            demMax = demChuSo[i];
        }
    }
    // liệt kê các chữ số xuất hiện nhiểu nhất
    printf("Cac chu so xuat hien nhieu nhat: ");
    for (int i = 0; i < 10; i++) {
        if (demChuSo[i] == demMax) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 6.4.20
void LietKeCacDongCoTongLonNhat(int a[][100], int dong, int cot) {
    int cacDongMax[dong], demDong=0;
    int maxDong;
    for (int i = 0; i < dong; i++) {
        int sum = 0;
        for (int j = 0; j < cot; j++) {
            sum += a[i][j];
        }
        if (i == 0 || sum > maxDong) {
            maxDong = sum;
            cacDongMax[0] = i;
            demDong = 1;
        }
        else if (sum == maxDong) {
            cacDongMax[demDong++] = i;
        }
    }

    printf("Cac dong co tong lon nhat: ");
    for (int i = 0; i < demDong; i++) {
        printf("%d ", cacDongMax[i]);
    }
    printf("\n");
}

// 6.4.21
void LietKeCacCotTongNhoNhat(int a[][100], int dong, int cot) {
    int cacCotMin[cot], demCot=0;
    int minCot;
    for (int i = 0; i < cot; i++) {
        int sum = 0;
        for (int j = 0; j < dong; j++) {
            sum += a[j][i];
        }
        if (i == 0 || sum < minCot) {
            minCot = sum;
            cacCotMin[0] = i;
            demCot = 1;
        }
        else if (sum == minCot) {
            cacCotMin[demCot++] = i;
        }
    }

    printf("Cac cot co tong nho nhat: ");
    for (int i = 0; i < demCot; i++) {
        printf("%d ", cacCotMin[i]);
    }
    printf("\n");
}

// 6.4.22
void LietKeDongNhieuSoChanNhat(int a[][100], int dong, int cot) {
    int cacDongNhieuChan[dong], demDong = 0;
    int maxDem = -1;
    for (int i = 0; i < dong; i++) {
        int demHienTai = 0;
        for (int j = 0; j < cot; j++) {
            if (a[i][j]%2 == 0) {
                demHienTai++;
            }
        }
        if (maxDem < demHienTai) {
            maxDem = demHienTai;
            cacDongNhieuChan[0] = i;
            demDong = 1;
        }
        else if (maxDem == demHienTai) {
            cacDongNhieuChan[demDong++] = i;
        }
    }
    if (maxDem <= 0) {
        printf("Ma tran khong co so chan\n");
    } else {
        printf("Cac dong nhieu so chan nhat: ");
        for(int i = 0; i < demDong; i++) {
            printf("%d ", cacDongNhieuChan[i]);
        }
        printf("\n");
    }
}

// 6.4.25
int DemSoLuongChuSo(int n) {
    n = abs(n);
    if (n == 0) return 1;
    int dem=0;
    while (n > 0) {
        dem++;
        n/=10;
    }
    return dem;
}
void LietKeCotNhieuChuSoNhat(int a[][100], int dong, int cot) {
    int cacCotMax[cot], demCot = 0;
    int maxChuSo = -1;
    for (int i = 0; i < cot; i++) {
        int demHienTai = 0;
        for (int j = 0; j < dong; j++) {
            demHienTai += DemSoLuongChuSo(a[i][j]);
        }

        if (demHienTai > maxChuSo) {
            maxChuSo = demHienTai;
            cacCotMax[0] = i;
            demCot = 1;
        } else if (demHienTai == maxChuSo) {
            cacCotMax[demCot++] = i;
        }
    }
    printf("Cac cot nhieu chu so nhat la: ");
    for (int i = 0; i < demCot; i++) {
        printf("%d ", cacCotMax[i]);
    }
    printf("\n");
}

// 6.4.26
// thuat toán kadane tim mảng con có tổng max
int Kadane(int a[], int &batDau, int &ketThuc, int n) {
    int maxSum = INT_MIN;
    int sum = 0, batDauTam = 0;
    ketThuc = -1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum < 0) {
            sum = 0;
            batDauTam = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            batDau = batDauTam;
            ketThuc = i;
        }
    }
// nếu ketThuc khác -1 tức là tìm ra đoạn max
    if (ketThuc != -1) {return maxSum;}
// nếu ketThuc = -1 tức là phần tử toàn âm
    maxSum = a[0];
    batDau = ketThuc = 0;
    for (int i = 1; i<n; i++) {
        if (a[i] > maxSum) {
            batDau = ketThuc = i;
            maxSum = a[i];
        }
    }
    return maxSum;
}

void TimMaTranConCoTongMax(int a[][100], int dong, int cot) {
    // áp dụng vòng lặp và thuật toán Kadane
    int maxSum = INT_MIN;
    int tren, duoi, trai, phai;
    int temp[dong], sum, batDau, KetThuc;

    for(int t = 0; t < cot; t++) 
    {
        for (int i = 0; i < dong; i++) {
            temp[i] = 0;
        }

        // cố định 1 cột bên trái và chạy từ trái sang phải dần
        for (int p = t; p < cot; p++) {
            // cộng dồn từ trái sang phải cho từng dòng để tìm giới hạn trên dưới max
            for (int i = 0; i < dong; i++) {
                temp[i] += a[i][p];
            }

            // áp dụng Kadane tìm điểm trên và dưới
            sum = Kadane(temp, batDau, KetThuc, dong);

            // cập nhật trên dưới trái phải
            if (sum > maxSum) {
                maxSum = sum;
                tren = batDau;
                duoi = KetThuc;
                trai = t;
                phai = p;
            }
        }
    } 

    printf("Ma tran con co tong lon nhat la: %d\n", maxSum);
    printf("Toa do tu hang (%d den %d), cot (%d den %d)", tren, duoi, trai, phai);
    printf("Phan tu trong ma tran con:\n");
    for (int i = tren; i <= duoi; i++) {
        for (int j = trai; j <= phai; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int a[100][100];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    // int n = timMax2Cach2(a,dong,cot);
    // printf("So lon thu 2 trong ma tran la %d\n", n);

    // int am = TimGiaTriAmLonNhat(a,dong,cot);
    // if (am == 0) {
    //     printf("Khong co gia tri am trong mang!\n");
    // } else {
    //     printf("Gia tri am lon nhat la: %d\n", am);
    // }

    // LietKeDongChuaMax(a,dong,cot);
    // GiaTriLonNhatTren1Dong(a,dong,cot);

    // int c = 2;
    // int r = TimGiaTriNhoNhatTren1Cot(a,dong,c);
    // printf("Gia tri nho nhat tren cot %d la %d\n", c,r);
    
    // int chanMax = TimSoChanLonNhat(a, dong,cot);
    // if (chanMax == -1) {
    //     printf("Khong co gia tri chan trong ma tran\n");
    // } else {
    //     printf("Gia tri chan lon nhat la %d\n", chanMax);
    // }

    // int d = DemSoLanXuatHienCuaSoNhoNhat(a,dong,cot);
    // printf("So lan xuat hien cua phan tu nho nhat la %d\n", d);
    
    // d = TimChuSoXuatHienNhieuNhat(a,dong,cot);
    // printf("Chu so xuat hien nhieu nhat la %d\n", d);

    // d = DemSoLuongChanNhoNhat(a,dong,cot);
    // if (d == 0) {
    //     printf("Khong co so chan trong mang\n");
    // } else {
    //     printf("So chan nho nhat xuat hien %d lan\n", d);
    // }

    // r = TimGiaTriXuatHienNhieuNhat(a,dong,cot);
    // printf("So xuat hien nhieu nhat la %d\n", r);

    // LietKeCacChuSoXuatHienNhieuNhat(a,dong,cot);

    // LietKeCacDongCoTongLonNhat(a, dong, cot);
    // LietKeCacCotTongNhoNhat(a,dong,cot);
    // LietKeDongNhieuSoChanNhat(a,dong,cot);

    // LietKeCotNhieuChuSoNhat(a,dong,cot);

    TimMaTranConCoTongMax(a,dong,cot);
    return 0;
}