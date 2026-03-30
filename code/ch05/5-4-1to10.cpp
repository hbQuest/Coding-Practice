#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int &n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

// 5.4.1
void lietKeSoAm(int a[], int n) {
    printf("Cac so am trong mang: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 5.4.2
void lietKeSoThuocDoanXY(int a[], int n, int x, int y) {
    printf("Cac so thuoc doan [%d,%d]: ", x, y);
    for (int i = 0; i < n; i++) {
        if (a[i] >= x && a[i] <= y) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 5.4.3
void lietKeSoChanThuocDoanXY(int a[], int n, int x, int y) {
    printf("Cac so chan thuoc doan [%d,%d]: ", x, y);
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0 && a[i] >= x && a[i] <= y) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 5.4.4
void lietKe1(int a[], int n) {
    bool flag = false;
    printf("Cac so lon hon tri tuyet doi so dung sau: ");
    for (int i = 0; i < n-1; i++) {
        if (a[i] > abs(a[i+1])) {
            flag = true;
            printf("%d ", a[i]);
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.5
void lietKe2(int a[], int n) {
    bool flag = false;
    printf("Cac so nho hon tri tuyet doi so dung sau va lon hon so truoc: ");
    for (int i = 1; i < n-1; i++) {
        if (a[i] < abs(a[i+1]) && a[i] > a[i-1]) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.6
void lietKe3(int a[], int n) {
    bool flag = false;
    if (n < 2) {
        printf("Mang qua ngan, khong co lan can\n");
        return;
    }
    printf("Cac so chan ma co it nhat 1 lan can cung chan: ");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i]%2 == 0 && a[i+1]%2 == 0) {
                flag = true;
                printf("%d ", a[i]);
            }
        } else if (i == n-1) {
            if (a[i]%2 == 0 && a[i-1]%2 == 0) {
                flag = true;
                printf("%d ", a[i]);
            }
        } else {
            if (a[i]%2 == 0 && (a[i-1]%2 == 0 || a[i+1]%2==0)) {
                flag = true;
                printf("%d ", a[i]);
            }
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.7
void lietKe4(int a[], int n) {
    bool flag = false;
    if (n < 2) {
        printf("Mang qua ngan, khong co lan can\n");
        return;
    }
    printf("Cac so ma co it nhat 1 lan can trai dau: ");
    for (int i = 0; i < n; i++) {
        int coLanCanTrai = false;
        int coLanCanPhai = false;
        if (i > 0 && a[i-1]*a[i] < 0) {
            coLanCanTrai = true;
        }
        if (i < n-1 && a[i+1]*a[i] < 0) {
            coLanCanPhai = true;
        }
        if (coLanCanPhai || coLanCanTrai) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.8
void lietKeViTriCoGiaTriMax(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("Vi tri chua gia tri lon nhat: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 5.4.9
bool checkSoNT(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n < 2 || n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2)==0) {
            return false;
        }
    }
    return true;
}
void lietKeViTriSoNT(int a[], int n) {
    bool flag = false;
    printf("Cac vi tri ma tai do la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (checkSoNT(a[i])) {
            printf("%d ", i);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.10
bool checkSoChinhPhuong(int n) {
    if (n < 0) {return false;}
    int canBacHai = (int)sqrt(n);
    if (canBacHai*canBacHai == n) {
        return true;
    }
    return false;
}
void lietKeViTriSoChinhPhuong(int a[], int n) {
    bool flag = false;
    printf("Cac vi tri ma tai do la so chinh phuong: ");
    for (int i = 0; i < n; i++) {
        if (checkSoChinhPhuong(a[i])) {
            printf("%d ", i);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");
    }
    printf("\n");
}

int main() {
    int a[100];
    int n;
    nhapMang(a,n);
    xuatMang(a,n);

    lietKeSoAm(a,n);
    int x,y;
    printf("Nhap doan (x,y)!\n");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    lietKeSoThuocDoanXY(a,n,x,y);
    lietKeSoChanThuocDoanXY(a,n,x,y);
    lietKe1(a,n);
    lietKe2(a,n);
    lietKe3(a,n);
    lietKe4(a,n);
    lietKeViTriCoGiaTriMax(a,n);
    lietKeViTriSoNT(a,n);
    lietKeViTriSoChinhPhuong(a,n);
    
    return 0;
}