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

void dichXuongQuayVongCacHang(int a[][100],int dong,int cot) {
    for (int i = dong-1; i >= 1; i--) {
        for (int j = 0; j < cot; j++) {
            hoanVi(a[i][j], a[i-1][j]);
        }
    }
}

// 6.5.4: Hoán vị hay xoay nên dùng biến tạm, gọi hàm nhiều dễ sai sót và không hiệu quả
void DichLenXoayVongCacHang(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong-1; i++) {
        for (int j = 0; j < cot; j++) {
            hoanVi(a[i][j], a[i+1][j]);
        }
    }

}

// 6.5.5
void DichTraiXoayVongCacCot(int a[][100], int dong, int cot) {
    for (int i = 0; i < cot -1 ; i++) {
        for (int j = 0; j < dong; j++) {
            hoanVi(a[j][i], a[j][i+1]);
        }
    }
}

// 6.5.6
void DichPhaiXoayVongCacCot(int a[][100], int dong, int cot) {
    for (int i = cot-1; i >= 1; i--) {
        for (int j = 0; j < dong; j++) {
            hoanVi(a[j][i], a[j][i-1]);
        }
    }
}

// 6.5.7
void DichPhaiXoayVongGiaTriTrenBien(int a[][100], int dong, int cot) {
    int temp = a[0][0];
    // cot 0: xoay lên từ dong 1
    for (int i = 0; i < dong -1 ;i++) {
        a[i][0] = a[i+1][0];
    }

    // dong - 1: xoay trái từ cot 0 đến cot-1
    for (int i = 0; i < cot - 1; i++) {
        a[dong-1][i] = a[dong-1][i+1];
    }

    // cot -1 : xoay xuống từ hàng-1 đến 0
    for (int i = dong-1; i >= 1; i--) {
        a[i][cot-1] = a[i-1][cot-1];
    }

    // hang 0: xoay phải từ cot-1 den cot 0
    for (int i = cot-1; i>=1; i--) {
        a[0][i] = a[0][i-1];
    }
    a[0][1] = temp;
}

// 6.5.8
void DichTraiXoayVongGiaTriTrenBien(int a[][100], int dong, int cot) {
    int temp = a[0][0];
    for (int i = 0; i < cot-1; i++) {
        a[0][i] = a[0][i+1];
    }
    for (int i = 0; i < dong-1; i++) {
        a[i][cot-1] = a[i+1][cot-1];
    }
    for (int i = cot-1; i >= 1; i--) {
        a[dong-1][i] = a[dong-1][i-1];
    }
    for (int i = dong-1; i > 1; i--) {
        a[i][0] = a[i-1][0];
    }
    a[1][0] = temp;
}

int main() {
    int a[100][100];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    dichXuongQuayVongCacHang(a,dong,cot);
    printf("Ma tran sau khi dich xuong quay vong cac hang:\n");
    xuat(a, dong, cot);
    
    DichLenXoayVongCacHang(a,dong,cot);
    printf("Ma tran sau khi dich len quay vong cac hang:\n");
    xuat(a, dong, cot);

    DichTraiXoayVongCacCot(a,dong,cot);
    printf("Ma tran sau khi dich trai quay vong cac cot:\n");
    xuat(a, dong, cot);

    DichPhaiXoayVongCacCot(a,dong,cot);
    printf("Ma tran sau khi dich phai quay vong cac cot:\n");
    xuat(a, dong, cot);

    DichPhaiXoayVongGiaTriTrenBien(a,dong,cot);
    printf("Ma tran sau khi dich phai quay vong cac gia tri tren bien:\n");
    xuat(a, dong, cot);

    DichTraiXoayVongGiaTriTrenBien(a,dong,cot);
    printf("Ma tran sau khi dich trai quay vong cac gia tri tren bien:\n");
    xuat(a, dong, cot);

    return 0;
}