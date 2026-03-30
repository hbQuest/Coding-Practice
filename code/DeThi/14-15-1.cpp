// De 2014-2015

#include <stdio.h>
#include <math.h>

void giaiPTBac4(int a,int b,int c) {

    if(a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem");
            } else {
                printf("Phuong trinh vo nghiem");
            }
        } else {
            double t = -c/b;
            if (t < 0) {
                printf("Phuong trinh vo nghiem");
            } else if (t == 0) {
                printf("Phuong trinh co 1 nghiem x = 0\n");
            } else {
                printf("Phuong trinh co 2 nghiem\n");
                printf("x1 = %.2lf\n", sqrt(t));
                printf("x2 = %.2lf\n", -sqrt(t));
            }
        }
    }

    double delta = (b*b) - (4*a*c);

    if (delta < 0) {
        printf("Phuong trinh vo nghiem");
    } else if (delta == 0) {
        double t = (-1.0*b) / (2*a);
        if (t < 0) {
            printf("Phuong trinh vo nghiem");
        } else if (t == 0) {
            printf("Phuong trinh co 1 nghiem x = 0\n");
        } else {
            printf("Phuong trinh co 2 nghiem\n");
            printf("x1 = %.2lf\n", sqrt(t));
            printf("x2 = %.2lf\n", -sqrt(t));
        }
    } else {
        double t1 = (-b + sqrt(delta)) / (2*a);
        double t2 = (-b - sqrt(delta)) / (2*a);
        if (t1 < 0 && t2 < 0) {
            printf("Phuong trinh vo nghiem");
            return;
        } 
        int soNghiem=0;
        printf("Phuong trinh co nghiem la:\n");
        if (t1 > 0) {
            printf("x%d = %.2lf\n", ++soNghiem, sqrt(t1));
            printf("x%d = %.2lf\n", ++soNghiem, -sqrt(t1));
        } else if (t1 == 0) {
            printf("x%d = 0", ++soNghiem);
        }
        if (t2 > 0) {
            printf("x%d = %.2lf\n", ++soNghiem, sqrt(t2));
            printf("x%d = %.2lf\n", ++soNghiem, -sqrt(t2));
        } else if (t2 == 0) {
            printf("x%d = 0", ++soNghiem);
        }
    }
}

void nhapMang(int a[],int &n) {
    printf("Nhap n so phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i);
        scanf("%d", &a[i]);
    }
}

void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (a[i] > a[j]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void xuatMangDaySoNguyenPhanBiet(int a[],int n) {
    // int b[100], m=0;
    // for (int i = 0; i < n; i++) {
    //     bool trung = false;
    //     for (int j = 0; j < m; j++) {
    //         if (a[i] == b[j]) {
    //             trung = true;
    //             break;
    //         }
    //     }
    //     if (!trung) {
    //         b[m] = a[i];
    //         m++;
    //     }
    // }
    // printf("Mang gom cac so nguyen phan biet la: ");
    // for (int i = 0; i < m; i++) {
        //     printf("%3d", b[i]);
        // }
        
    // cach khac la sap xep theo thu tu tang dan roi in ra neu so do trung so truoc thi khong in ra
        
    printf("Mang gom cac so nguyen phan biet la: ");
    sapXepTangDan(a,n);
    if (n > 0) {
        printf("%3d", a[0]);
    }
    for (int i = 1 ; i < n; i++) {
        if (a[i] != a[i-1]) {
            printf("%3d", a[i]);
        }
    }
}

struct DaGiac{
    int soDinh = 0;
    double doDaiCanh[100];
};

void nhapDaGiac(DaGiac &dg) {
    do {
        printf("Nhap so dinh (>=3): ");
        scanf("%d", &dg.soDinh);
        if (dg.soDinh<3) {
            printf("Xin nhap lai!\n");
        }
    } while (dg.soDinh<3);

    for (int i = 0; i < dg.soDinh; i++) {
        printf("Nhap do dai canh %d: ", i+1);
        scanf("%lf", &dg.doDaiCanh[i]);
    }
}

double tinhChuVi(DaGiac dg) {
    double chuVi=0.0;
    for (int i = 0; i < dg.soDinh; i++) {
        chuVi += dg.doDaiCanh[i];
    }
    return chuVi;
}

void nhapMang2Chieu(int a[][100], int &dong, int &cot) {
    printf("Nhap so dong: ");
    scanf("%d", &dong);
    printf("Nhap so cot: ");
    scanf("%d", &cot);
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

int timChuSoXuatHienItNhat(int a[][100], int dong, int cot) {
    int b[10];
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            int so = abs(a[i][j]);
            if (so == 0) {
                b[so]++;
            } else {
                while (so != 0) {
                    int chuSo = so % 10;
                    b[chuSo]++;
                    so /= 10;
                }
            }
        }
    }
    int min=1000000, num=-1;
    for (int i = 1; i < 10; i++) {
        if (b[i] < min && b[i] != 0) {
            num = i;
            min = b[i];
        }
    }
    return num;
}
int main() {
    // int a,b,c;

    // printf("Nhap a: ");
    // scanf("%d", &a);
    // printf("Nhap b: ");
    // scanf("%d", &b);
    // printf("Nhap c: ");
    // scanf("%d", &c);

    // giaiPTBac4(a,b,c);

    // int a[100];
    // int n;
    // nhapMang(a,n);
    // xuatMangDaySoNguyenPhanBiet(a,n);

    // DaGiac dg;
    // nhapDaGiac(dg);

    // double chuVi = tinhChuVi(dg);
    // printf("Chi vi da giac %d dinh la: %.2lf", dg.soDinh, chuVi);

    int a[100][100];
    int cot, dong;
    nhapMang2Chieu(a, dong, cot);
    int c = timChuSoXuatHienItNhat(a,dong, cot);
    if (c != -1) {
        printf("Chu so xuat hien it nhat trong mang la: %d", c);
    } else {
        printf("Mang khong hop le khong co chu so nao");
    }
    return 0;
}