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


void xoa1Dong(int a[][100],int& dong,int cot, int d) {
    if (d - 1 < dong) {
        for (int i = d; i < dong-1; i++) {
            for (int j = 0; j < cot; j++) {
                a[i][j] = a[i+1][j];
            }
        }
    }
    dong--;
}

// 6.5.10
void Xoa1Cot(int a[][100], int dong, int &cot, int c) {
    if (c-1 < cot) {
        for (int j = c; j < cot - 1; j++) {
            for (int i = 0; i < dong; i++) {
                a[i][j] = a[i][j+1];
            }
        }
    }
    cot--;
}

// 6.5.11 
void Xoay90Do(int a[][100], int &dong, int &cot) {
    int n = dong*cot;
    int temp[n];
    int dem=0;
    for (int j = 0; j < cot; j++) {
        for (int i = dong-1; i >= 0; i--) {
            temp[dem++] = a[i][j];
        }
    }
    int dongTam = dong;
    dong = cot;
    cot = dongTam;
    dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = temp[dem++];
        }
    }
}

// 6.5.11 : cách 2
void Xoay90DoCach2(int a[][100], int &dong, int &cot) {
    int b[100][100];
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[j][dong-i-1] = a[i][j];
        }
    }
    int dongTam = dong;
    dong = cot;
    cot = dongTam;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = b[i][j];
        }
    }
}

// 6.5.12
void Xoay180Do(int a[][100], int &dong, int &cot) {
    int b[100][100];

    for (int i = dong-1; i>=0; i--) {
        for (int j = cot-1; j >= 0; j--) {
            b[dong-i-1][cot-j-1] = a[i][j];
        }
    }
    
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = b[i][j];
        }
    }
}

// 6.5.13
void Xoay270Do(int a[][100], int &dong, int &cot) {
    int b[100][100];
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[cot - j - 1][i] = a[i][j];
        }
    }
    int dongTam = dong;
    dong = cot;
    cot = dongTam;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = b[i][j];
        }
    }
}

// 6.5.14
void hoanVi(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void ChieuGuongTheoTrucDoc(int a[][100], int dong, int cot) {
    int c = 0;
    while(c != cot/2) {
        for (int i = 0; i < dong; i++) {
            hoanVi(a[i][c],a[i][cot-c-1]);
        }
        c++;
    }
}

// 6.5.15
void ChieuGuongTheoTrucNgang(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong/2; i++) {
        for (int j = 0; j < cot; j++) {
            hoanVi(a[i][j], a[dong-i-1][j]);
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
    //     printf("Nhap dong muon xoa: ");
    //     scanf("%d", &d);
    //     if (d < 0 || d >= dong) {
    //         printf("Dong khong hop le! Xin nhap lai!");
    //     }
    // } while (d < 0 || d >= dong);

    // xoa1Dong(a,dong,cot,d);
    // printf("Ma tran sau khi xoa dong %d:\n", d);
    // xuat(a, dong, cot);
    
    // int c;
    // do {
    //     printf("Nhap cot muon xoa: ");
    //     scanf("%d", &c);
    //     if (c < 0 || c >= cot) {
    //         printf("Cot khong hop le! Xin nhap lai!");
    //     }
    // } while (c < 0 || c >= cot);

    // Xoa1Cot(a,dong,cot,c);
    // printf("Ma tran sau khi xoa cot %d:\n", c);
    // xuat(a, dong, cot);

    // printf("Xoay 90 do\n");
    // Xoay90DoCach2(a,dong,cot);
    // xuat(a,dong,cot);
    
    // printf("Xoay 180 do\n");
    // Xoay180Do(a,dong,cot);
    // xuat(a,dong,cot);

    printf("Xoay 270 do\n");
    Xoay270Do(a,dong,cot);
    xuat(a,dong,cot);
    
    
    printf("Chieu guong ma tran theo truc doc\n");
    ChieuGuongTheoTrucDoc(a,dong,cot);
    xuat(a,dong,cot);

    printf("Chieu guong ma tran theo truc ngang\n");
    ChieuGuongTheoTrucNgang(a,dong,cot);
    xuat(a,dong,cot);

    return 0;
}

/*Góc xoay (Clockwise),Công thức biến đổi tương ứng
90 độ,b[j][dong - 1 - i] = a[i][j]
180 độ,b[dong - 1 - i][cot - 1 - j] = a[i][j]
270 độ,b[cot - 1 - j][i] = a[i][j]*/