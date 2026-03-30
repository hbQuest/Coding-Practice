#include <stdio.h>

void nhapMang(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    putchar('\n');
}

void doiCho(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void diChuyen0(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if(a[i] == 0) {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 != 0) {
                    doiCho(a[i], a[j-1]);
                    break;
                }
            }
        }
    }
}
void xepChanLeChen0(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]%2 != 0) {
            for (int j = i + 1; j < n; j++) {
                if (a[j]%2 == 0) {
                    doiCho(a[i], a[j]);
                    break;
                }
            }
        }
    }
    diChuyen0(a, n);
}

// cach 2: dua chan ve dau, le ve cuoi bang index roi chen 0 vao giua
void xepChanLe(int a[], int n) {
    int indexChan=0, indexLe=n-1;
    int temp[n];
    for (int i = 0; i < n; i++) {
        if (a[i]%2 != 0) {
            temp[indexLe--] = a[i];
        } else if (a[i]%2 == 0 && a[i] != 0) {
            temp[indexChan++] = a[i];
        }
    }

    for (int i = indexChan; i <= indexLe; i++) {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

// cach 3: dung phuong phap 3 diem neo
void xepChanLeCach3(int a[], int n) {
    int dau = 0, giua = 0, cuoi = n-1;
    while (giua <= cuoi) {
        if (a[giua]!=0 && a[giua]%2 == 0) {
            doiCho(a[dau], a[giua]);
            giua++;
            dau++;
        } else if (a[giua] == 0) {
            giua++;
        } else {
            doiCho(a[giua], a[cuoi]);
            cuoi--;
        }
    }
}

// 5.10.3
void DuaSoChiaHetCho3VeDauMang(int a[], int n) {
    for (int i = 0; i<n; i++) {
        if (a[i]%3 != 0) {
            for (int j = i+1; j < n; j++) {
                if (a[j]%3 ==0) {
                    doiCho(a[i], a[j]);
                }
            }
        }
    }
}

// 5.10.3 phuong phap 2 diem neo
void DuaSoChiaHetCho3VeDauMangCach2(int a[], int n) {
    int viTriTiepTheo = 0;
    for (int i = 0; i<n; i++) {
        if (a[i]%3 == 0) {
            doiCho(a[i], a[viTriTiepTheo]);
            viTriTiepTheo++;
        }
    }
}

// 5.10.4
void daoNguocMang(int a[], int n) {
    int temp[n];
    for (int i = n-1; i >=0; i--) {
        temp[n-i-1] = a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

// 5.10.4
void daoNguocMangCach2(int a[], int n) {
    int dau = 0;
    int cuoi = n-1;
    while (dau < cuoi) {
        doiCho(a[dau], a[cuoi]);
        dau++;
        cuoi--;
    }
}

// 5.10.5
void daoNguocThuTuSoChan(int a[], int n) {
    int dau = 0;
    int cuoi = n-1;
    while (dau < cuoi) {
        if (a[dau]%2 == 0 && a[cuoi]%2 == 0) {
            doiCho(a[dau], a[cuoi]);
            dau++;
            cuoi--;
        } else {
            if (a[dau]%2 != 0) {
                dau++;
            } 
            if (a[cuoi]%2 != 0) {
                cuoi--;
            }
        }
    }
}

// 5.10.6
void daoNguocThuTuSoDuong(int a[], int n) {
    int dau = 0;
    int cuoi = n-1;
    while (dau < cuoi) {
        if (a[dau] > 0 && a[cuoi] > 0) {
            doiCho(a[dau], a[cuoi]);
            dau++;
            cuoi--;
        } else {
            if (a[dau] <= 0) {
                dau++;
            } 
            if (a[cuoi] <= 0) {
                cuoi--;
            }
        }
    }
}

// 5.10.6 Cách 2
void daoNguocThuTuSoDuongCach2(int a[], int n) {
    int dau = 0;
    int cuoi = n-1;
    while (dau < cuoi) {
        while (dau < cuoi && a[dau] <= 0) {
            dau++;
        }
        while (dau < cuoi && a[cuoi] <= 0) {
            cuoi--;
        }
        if (dau < cuoi) {
            doiCho(a[dau],a[cuoi]);
            dau++;
            cuoi--;
        }
    }
}

// 5.10.7
void DichTraiXoayVongKPhanTu(int a[], int n, int k) {
    k = k%n;
    for (int i = 1; i <= k; i++) {
        int temp = a[0];
        for (int j = 0; j < n-1; j++) {
            a[j] = a[j+1];
        }
        a[n-1] = temp;
    }
}

// cach 2: cong thuc dao nguoc 3 lan
void daoNguoc(int a[], int dau, int cuoi) {
    while (dau < cuoi)
    {
        doiCho(a[dau], a[cuoi]);
        dau++;
        cuoi--;
    }
}

void DichTraiXoayVongKPhanTuCach2(int a[], int n, int k) {
    k = k%n;
    if (k == 0) return;

    daoNguoc(a,0,k-1);
    daoNguoc(a,k,n-1);
    daoNguoc(a,0,n-1);
}

// 5.10.8
void DichPhaiXoayVongKPhanTu(int a[], int n, int k) {
    k = k%n;
    if (k == 0) {return;}
    daoNguoc(a,0,n-1);
    daoNguoc(a,0,k-1);
    daoNguoc(a,k,n-1);
}

// 5.10.9
void XuatPhanTuChanVangLeChan(int a[], int n) {
    printf("Mang theo yeu cau: ");
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            // \033[1;33m là mã màu Vàng
            printf("\033[1;33m%d \033[0m", a[i]);
        } else {
            // \033[1;37m là mã màu Trắng sáng
            printf("\033[1;37m%d \033[0m", a[i]);
        }
    }
    printf("\n");
}

// 5.10.10
void XuatMangChan1HangLe1Hang(int a[], int n) {
    printf("Mang chan 1 hang, le hang tiep theo!\n");
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (a[i]%2 != 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 5.10.11
void DaoNguocSoThuTuChanLe(int a[], int n) {
    //dao chan
    int dau = 0, cuoi = n-1;
    while (dau < cuoi) {
        while (dau < cuoi && a[dau]%2 != 0) {
            dau++;
        }
        while (dau < cuoi && a[cuoi]%2 != 0) {
            cuoi--;
        }
        if (dau < cuoi) {
            doiCho(a[dau], a[cuoi]);
            dau++;
            cuoi--;
        }
    }
    // dao le
    dau = 0, cuoi = n-1;
    while (dau < cuoi) {
        while (dau < cuoi && a[dau]%2 == 0) {
            dau++;
        }
        while (dau < cuoi && a[cuoi]%2 == 0) {
            cuoi--;
        }
        if (dau < cuoi) {
            doiCho(a[dau], a[cuoi]);
            dau++;
            cuoi--;
        }
    }
}

// 5.10.12
void BienDoiThayMaxBangMin(int a[], int n) {
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    if (max == min) return;
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            a[i] = min;
        } else if (a[i] == min) {
            a[i] = max;
        }
    }
}

//5.10.13
void nhapMangSoThuc(double b[],int& m) {
    do {
        printf("Nhap so phan tu m: ");
        scanf("%d", &m);
        if (m <= 0 || m > 100) {
            printf("Xin nhap lai!\n");
        }
    } while(m <= 0 || m > 100);
    for (int i = 0; i < m; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%lf", &b[i]);
    }
}
void LamTronMangSoThuc(int a[], double b[], int n) {
    
    for (int i = 0; i < n; i++) {
        if (b[i] >= 0) {
            a[i] = (int)(b[i] + 0.5);
        } else {
            a[i] = (int)(b[i] - 0.5);
        }
    }
}

int main() {
    int a[100];
    int n;
    printf("Xin nhap mang A:\n");
    nhapMang(a,n);
    xuatMang(a,n);

    // printf("Mang A sau dua chan ve dau, le ve cuoi, 0 nam giua mang:\n");
    // xepChanLeCach3(a,n);
    // xuatMang(a,n);

    // printf("Dua so chia het cho 3 ve dau!\n");
    // DuaSoChiaHetCho3VeDauMangCach2(a,n);
    // xuatMang(a,n);

    // daoNguocMangCach2(a,n);
    // printf("Mang dao nguoc!\n");
    // xuatMang(a,n);

    // daoNguocThuTuSoChan(a,n);
    // printf("Mang sau khi dao nguoc thu tu so chan!\n");
    // xuatMang(a,n);

    // daoNguocThuTuSoDuongCach2(a,n);
    // printf("Mang sau khi dao nguoc thu tu so duong!\n");
    // xuatMang(a,n);

    // int k;
    // printf("Nhap so phan tu dich sang phai k = ");
    // scanf("%d", &k);
    // DichPhaiXoayVongKPhanTu(a,n,k);
    // printf("Mang sau khi dich trai xoay vong %d phan tu!\n", k);
    // xuatMang(a,n);


    // XuatPhanTuChanVangLeChan(a,n);
    // XuatMangChan1HangLe1Hang(a,n);
    // DaoNguocSoThuTuChanLe(a,n);
    // xuatMang(a,n);

    // BienDoiThayMaxBangMin(a,n);
    // xuatMang(a,n);

    double b[100];
    int m;
    nhapMangSoThuc(b,m);
    LamTronMangSoThuc(a,b,n);
    printf("Mang b sau lam tron!\n");
    xuatMang(a,m);
    return 0;
}

