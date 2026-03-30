#include <math.h>
#include <stdio.h>

double sqrt_N(double x, int n, bool& errorFlag) {
    double Result = 0;
    errorFlag = false;

    if (n == 0) {
        errorFlag = true;
    }
    else if (n < 0) {
        if (x == 0) {
            errorFlag = true;
        }
        else {
            // Sửa logic: Gọi đệ quy với -n (số dương) và truyền đủ 3 tham số
            double temp = sqrt_N(x, -n, errorFlag);
            if (!errorFlag) {
                Result = 1.0 / temp;
            }
        }
    }
    else { // Truong hop n > 0
        if (x >= 0) {
            Result = pow(x, 1.0 / n);
        }
        else { // Truong hop x < 0
            if (n % 2 != 0) { // Sửa lại: Dùng n % 2 != 0 cho số lẻ để an toàn hơn với số âm
                // Gọi đệ quy với số dương -x và truyền đủ 3 tham số
                Result = -sqrt_N(-x, n, errorFlag); 
            }
            else { // Thay cho chữ 'ele' bị sai
                errorFlag = true;
            }
        }
    }

    return Result;
}

int main() {
    double x = -9.0;
    int n = 2;
    bool errorFlag;
    double ketQua = sqrt_N(x,n,errorFlag);
    if (!errorFlag) {
        printf("%.2lf", ketQua);
    } else {
        printf("Khong hop le!");
    }
    return 0;
}