#include <stdio.h>
#include <math.h>

void nhap(int a[][100], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > 100) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//  7.5.1
void SapCheoChinhTangDan(int a[][100], int n) {
    for (int i = 0 ; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i][i] > a[j][j]) {
                hoanVi(a[i][i], a[j][j]);
            }
        }
    }
}
// 7.5.2
void SapCheoPhuGiamDan(int a[][100], int n) {
    for (int i = 0; i<n ; i++) {
        for (int j = i+1 ; j < n; j++) {
            if (a[i][n-1-i] < a[j][n-1-j]) {
                hoanVi(a[i][n-1-i],a[j][n-1-j]);
            }
        }
    }
}
// 7.5.3
void HoanVi2Dong(int a[][100], int n, int d1, int d2) {
    for (int j = 0; j < n; j++) {
        hoanVi(a[d1][j], a[d2][j]);
    }
}
// 7.5.4
void HoanVi2Cot(int a[][100], int n, int c1, int c2) {
    for (int i = 0; i < n; i++) {
        hoanVi(a[i][c1], a[i][c2]);
    }
}
// 7.5.5
void sapXepTangDanTheoTongDong(int a[][100], int n) {
    int b[100] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i] += a[i][j];
        }
    }
    
    // sap xep mang 1 chieu b voi phan tu la tong cac dong
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
                for (int k = 0; k < n; k++) {
                    hoanVi(a[i][k], a[j][k]);
                }
            }
        }
    }
}
// 7.5.6
void DuaChanVeDauMaTran(int a[][100], int n) {
    int k = n*n;
    for (int i = 0; i < k-1; i++) {
        int d1 = i/n;
        int c1 = i%n;
        if (a[d1][c1]%2 != 0) {
            bool timThayChan = false;
            for (int j = i+1; j < k; j++) {
                int d2 = j/n;
                int c2 = j%n;
                if(a[d2][c2]%2 == 0) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                    timThayChan = true;
                    break;
                }
            }
            if (!timThayChan) {
                return;
            }
        }
    }
}

// 7.5.6 cách 2: phương pháp 2 con trỏ
void DuaChanVeDauConTro(int a[][100], int n) {
    int k = n*n;
    int viTriChan = 0;
    for (int i = 0; i < k; i++) {
        int dongHienTai = i/n;
        int cotHienTai = i%n;

        if (a[dongHienTai][cotHienTai]%2 == 0) {
            int dong_viTriChan = viTriChan/n;
            int cot_viTriChan = viTriChan%n;
            hoanVi(a[dongHienTai][cotHienTai], a[dong_viTriChan][cot_viTriChan]);

            viTriChan++;
        }
    }
}
//7.5.7
void SapTamGiacTrenTang(int a[][100], int n) {
    int k = n*n;
    int b[k];
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j< n; j++) {
            b[dem++] = a[i][j];
        }
    }
    // sap xep mang 1 chieu tam giac tren
    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
    dem=0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j< n; j++) {
            a[i][j] = b[dem++];
        }
    }
}
// 7.5.8
void SapTamGiacDuoiGiam(int a[][100], int n) {
    int k = n*n;
    int b[k];
    int dem = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            b[dem++] = a[i][j];
        }
    }
    // sap xep mang 1 chieu tam giac tren
    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[i] < b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
    dem=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< i; j++) {
            a[i][j] = b[dem++];
        }
    }
}
// 7.5.9
void XayDungMaPhuongLe(int a[][100], int n) {
    // Khởi tạo ma trận toàn số 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    int r = 0;          // Dòng hiện tại
    int c = n / 2;      // Cột hiện tại (giữa dòng đầu)

    for (int k = 1; k <= n * n; k++) {
        a[r][c] = k;

        // Lưu lại vị trí cũ để dự phòng trường hợp ô tiếp theo đã có số
        int r_cu = r;
        int c_cu = c;

        // Thử di chuyển lên trên 1 và sang phải 1
        r = r - 1;
        c = c + 1;

        // Xử lý tràn biên
        if (r < 0) r = n - 1;
        if (c == n) c = 0;

        // Nếu ô đó đã được điền số, quay lại vị trí cũ và đi xuống 1 dòng
        if (a[r][c] != 0) {
            r = r_cu + 1;
            c = c_cu;
            // Lưu ý: vị trí mới này luôn đảm bảo trống đối với n lẻ
        }
    }
}

// 7.5.9
void XayDungMaPhuong(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    int dem=1;
    int dong = 0;
    int cot = n / 2;
    while (dem <= n*n) {
        a[dong][cot] = dem++;

        int dongCu = dong;
        int cotCu = cot;

        dong = dong - 1;
        cot = cot + 1;

        if (dong < 0) {dong = n - 1;}
        if (cot == n) { cot = 0;}

        if (a[dong][cot] != 0) {
            dong = dongCu + 1;
            cot = cotCu;
        }
    }
}

void XayDungMaPhuongChanKep(int a[][100], int n) {
    // 1. Điền số từ 1 đến n*n theo thứ tự từ trái sang phải, trên xuống dưới
    int dem = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = dem++;
        }
    }

    // 2. Đảo ngược giá trị tại các vị trí thỏa mãn quy luật đường chéo khối 4x4
    // Công thức đảo: giá trị mới = (n*n + 1) - giá trị cũ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Quy luật cho các ô thuộc đường chéo của các khối 4x4
            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) {
                a[i][j] = (n * n + 1) - a[i][j];
            }
        }
    }
}

int main() {
    int a[100][100];
    int n;

    // nhap(a,n);
    // xuat(a,n);
    
    // printf("Ma tran sau khi sap xep theo tong tung dong tang dan:\n");
    // sapXepTangDanTheoTongDong(a,n);
    // xuat(a,n);
    
    // printf("Ma tran sau khi sap xep cheo chinh tang dan:\n");
    // SapCheoChinhTangDan(a,n);
    // xuat(a,n);
    
    // printf("Ma tran sau khi sap xep cheo phu giam dan:\n");
    // SapCheoPhuGiamDan(a,n);
    // xuat(a,n);
    
    // int d1,d2;
    // do {
    //     printf("Nhap 2 dong muon hoan vi:\n");
    //     printf("D1: ");
    //     scanf("%d", &d1);
    //     printf("D2: ");
    //     scanf("%d", &d2);
    //     if (d1 < 0 || d1 >= n || d2 < 0 || d2 >= n) {
    //         printf("Loi! Xin nhap lai!\n");
    //     }
    // } while (d1 < 0 || d1 >= n || d2 < 0 || d2 >= n);
    // HoanVi2Dong(a,n,d1,d2);
    // xuat(a,n);
    
    // printf("Ma tran sau khi dua chan ve dau:\n");
    // DuaChanVeDauConTro(a,n);
    // xuat(a,n);
    
    // printf("Ma tran sau khi sap xep tam giac tren tang:\n");
    // SapTamGiacTrenTang(a,n);
    // xuat(a,n);
    
    // printf("Ma tran sau khi sap xep tam giac duoi giam:\n");
    // SapTamGiacDuoiGiam(a,n);
    // xuat(a,n);

    n = 4;

    if (n%4 == 0) {
        XayDungMaPhuongChanKep(a,n);
        xuat(a,n);
    } else if (n%2 != 0) {
        XayDungMaPhuong(a, n);
        xuat(a, n);
    } else if (n%2 == 0) {
        printf("Thuat toan nay chi ap dung cho n le hoac thuat toan phuc tap hon!\n");
    }

    return 0;
}   