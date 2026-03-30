#include <stdio.h>
#define MAX 100

void input(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    putchar('\n');
}

bool checkPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n%i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    } else {
        return false;
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void perfectSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (checkPerfect(a[i])) {
            for (int j = i+1; j < n; j++) {
                if (checkPerfect(a[j])) {
                    if (a[i] > a[j]) {
                        swap(a[i], a[j]);
                    }
                }  
            }
        }
    }
}

// 5.7.6
void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j =i+1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

bool laHoanViCuaMangA(int a[], int b[], int n, int m) {
    if (n != m) { return false;}
    int tempA[n];
    int tempB[m];
    for (int i = 0; i < n; i++) {
        tempA[i] = a[i];
        tempB[i] = b[i];
    }
    sapXepTangDan(tempA,n);
    sapXepTangDan(tempB,m);
    for (int i = 0; i < n; i++)
    {
        if (tempA[i] != tempB[i]) {
            return false;
        }
    }
    return true;
}

// 5.7.8
void sapXepChanLeTangDan(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i]%2 == 0) {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 == 0 && a[j] < a[i]) {
                    swap(a[i], a[j]);
                }
            }
        } else {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 != 0 && a[j] < a[i]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
}

// 5.7.9
void sapXepChanTangLeGiam(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i]%2 == 0) {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 == 0 && a[j] < a[i]) {
                    swap(a[i], a[j]);
                }
            }
        } else {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 != 0 && a[j] > a[i]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
}

int main() {
    int a[MAX];
    int n;

    printf("Nhap mang A!\n");
    input(a, n);
    
    printf("Sau khi sap xep so hoan hao tang dan\n");
    perfectSort(a, n);
    display(a, n);
    
    // int b[100];
    // int m;
    // printf("Nhap mang B!\n");
    // input(b, m);
    // bool ketQua = laHoanViCuaMangA(a,b,n,m);
    // if (ketQua) {
    //     printf("Mang b la hoan vi cua mang a\n");
    // } else {
    //     printf("Mang b khong la hoan vi cua mang a\n");
    
    // }
    
    printf("Sau khi sap xep chan le tang dan\n");
    sapXepChanLeTangDan(a,n);
    display(a,n);

    printf("Sau khi sap xep chan tang dan le giam dan\n");
    sapXepChanTangLeGiam(a,n);
    display(a,n);
    return 0;
}
