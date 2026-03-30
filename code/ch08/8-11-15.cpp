#include <stdio.h>
#include <string.h>

struct Tinh {
    int maTinh;
    char ten[31];
    double dienTich;
};

void nhapThongTin(Tinh &tinh) {
    printf("Nhap ma tinh: ");
    scanf("%d", &tinh.maTinh);
    printf("Nhap ten tinh (viet lien duoi 30 ki tu): ");
    // Dùng 3 bước sau sẽ lấy được khoảng trắng: 1 bỏ \n trong buffer, 2 nhận input lấy cả space và \n, 3 xoá \n khỏi input
    // getchar();
    // fgets(tinh.ten, sizeof(tinh.ten), stdin);
    // tinh.ten[strcspn(tinh.ten, "\n")] = 0;

    scanf("%s", tinh.ten);
    printf("Nhap dien tich: ");
    scanf("%lf", &tinh.dienTich);
}
void xuatThongTin(Tinh tinh) {
    printf("Thong tin tinh:\n");
    printf("Ma tinh: %d\n", tinh.maTinh);
    printf("Ten tinh: ");
    puts(tinh.ten);
    printf("Dien tich(km2): %.4lf\n", tinh.dienTich);
}

int main() {
    Tinh tinh1;
    nhapThongTin(tinh1);
    xuatThongTin(tinh1);

    return 0;
}