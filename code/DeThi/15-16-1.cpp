// De HK1 2015-2016

#include <stdio.h>
#include <math.h>

// Bai 1
void inTamGiacChieuCaoN(int n) {
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (j <= i) {
                printf(" ");
            } else {
                printf("%d", j);
                if (j == n) {
                    for (int k = n-1; k > 0; k--) {
                        if (k <= i) {
                            printf(" ");
                        } else {
                            printf("%d", k);
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
}

// Bai 2

void chuyenSoNguyenThanhKyTu(int num, char so[]) {
    char a[100];
    int temp = abs(num), i=0;

    while (temp > 0) {
        int donVi = temp%10;
        char chuSo = '0' + donVi;
        a[i++] = chuSo;
        temp /= 10;
    }
    if (num < 0) {
        a[i++] = '-';
    }
    a[i] = '\0';
    
    int k = 0;
    for (int j=i-1 ; j >= 0; j--) {
        so[k++] = a[j];
    }
    so[k]='\0';
}


// Bai 3
void nhapMaTran(int maTran[][100],int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Nhap maTran[%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
    printf("\n");
}

void inGiaTriLonNhatDongNhoNhatCot(int maTran[][100],int n) {

    bool lonDong, nhoCot;
    
    printf("Gia tri lon nhat dong va nho nhat cot cua no la: ");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num = maTran[i][j];
            lonDong = true;
            nhoCot=true;
            for (int k = 0; k < n; k++) {
                if (maTran[i][k] > num) {
                    lonDong = false;
                    break;
                }
            }
            if (lonDong) {
                for (int t = 0; t < n; t++) {
                    if (num > maTran[t][j]) {
                        nhoCot = false;
                        break;
                    }
                }
            }
            if (lonDong&&nhoCot) {
                printf("%d ", num);
            }
        }
    }
}

// Bai 4
struct Diem {
    double x;
    double y;
};

struct DuongTron {
    Diem tam;
    double banKinh;
};

void nhapDuongTron(DuongTron &dt ){
    printf("Nhap toa do tam:\n");
    printf("Hoanh do: ");
    scanf("%lf", &dt.tam.x);
    printf("Tung do: ");
    scanf("%lf", &dt.tam.y);
    printf("Nhap ban kinh: ");
    scanf("%lf", &dt.banKinh);
}

void xuatDuongTron(DuongTron &dt) {
    printf("Toa do tam (%.2lf,%.2lf), ban kinh %.2lf\n", dt.tam.x, dt.tam.y, dt.banKinh);
}

bool xacDinhGiaoNhau(DuongTron dt1, DuongTron dt2) {
    double khoangCachTam = sqrt(pow(dt2.tam.x - dt1.tam.x, 2) + pow(dt2.tam.y - dt1.tam.y, 2));
    double tongBanKinh = dt2.banKinh+dt1.banKinh;
    double hieuBanKinh = abs(dt2.banKinh-dt1.banKinh);
    if (khoangCachTam <= tongBanKinh && khoangCachTam >= hieuBanKinh) {
        return true;
    } else {
        return false;
    }
}


// Bai 5
struct HocSinh {
    char maHS[50];
    char tenHS[100];
    int diem;
};

void docFile(const char* tenFile, HocSinh ds[], int& n) {
    FILE* f = fopen(tenFile, "rt");
    if (f == NULL) {
        printf("Khong mo duoc!");
        return;
    }

    fscanf(f, "%d", &n);

    fgetc(f); // read the \n 

    // for(int i = 0; i < n; i++) {
    //     fscanf(f, "%[^|]|%[^|]|%d", ds[i].maHS, ds[i].tenHS, &ds[i].diem);
    // }
    for(int i = 0; i < n; i++) {
        char c;
        int j = 0;
        while ((c = fgetc(f)) != '|' && c != EOF) {
            ds[i].maHS[j++] = c; 
        }
        ds[i].maHS[j] = '\0';
        
        j=0;
        while ((c = fgetc(f)) != '|' && c != EOF) {
            ds[i].tenHS[j++] = c; 
        }
        ds[i].tenHS[j] = '\0';
        fscanf(f, "%d", &ds[i].diem);
        fgetc(f); // read the \n
    }

    fclose(f);
}

void ghiFile(const char* tenFile, HocSinh ds[], int n) {
    FILE* f = fopen(tenFile, "wt");
    if (f == NULL) {
        printf("Khong mo duoc!");
        return;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 8) {
            count++;
        }
    }

    fprintf(f, "%d\n", count);

    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 8) {
            
            fprintf(f, "%s|%s|%d\n", ds[i].maHS, ds[i].tenHS, ds[i].diem);
        }
    }

    fclose(f);
}

int main() {
    int n; 
    printf("Nhap n: ");
    scanf("%d", &n);
    inTamGiacChieuCaoN(n);

    // int num;
    // char so[100];
    // printf("Nhap so nguyen: ");
    // scanf("%d", &num);
    // chuyenSoNguyenThanhKyTu(num, so);
    // printf("So nguyen dang chuoi la: %s", so);

    // int maTran[100][100];
    // int n;
    // printf("Nhap so nguyen: ");
    // scanf("%d", &n);
    // nhapMaTran(maTran, n);
    // inGiaTriLonNhatDongNhoNhatCot(maTran, n);

    // DuongTron dt1, dt2;
    // printf("Nhap duong tron 1:\n");
    // nhapDuongTron(dt1);
    // printf("Nhap duong tron 2:\n");
    // nhapDuongTron(dt2);
    // printf("Duong tron 1:\n");
    // xuatDuongTron(dt1);
    // printf("Duong tron 2:\n");
    // xuatDuongTron(dt2);
    // if (xacDinhGiaoNhau(dt1, dt2)) {
    //     printf("Hai duong tron CO giao nhau (cat nhau tai it nhat mot diem)");
    // } else {
    //     printf("Hai duong tron KHONG giao nhau");
    // }

    // int n = 0;
    // HocSinh danhSachHS[100];

    // docFile("INPUT.txt", danhSachHS, n);

    // if (n > 0) {
    //     ghiFile("OUTPUT.txt", danhSachHS, n);
    //     printf("Da ghi xong!");
    // }

    return 0;
}