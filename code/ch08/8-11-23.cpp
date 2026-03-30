#include <stdio.h>
#define MAXTEN 31
#define MAXMA 6

struct ThiSinh {
    char maThiSinh[MAXMA];
    char tenthiSinh[MAXTEN];
    double diemToan, diemLy, diemHoa, diemTongCong;
};

void nhapThongTin(ThiSinh& h) {
    printf("Nhap ma thi sinh (viet lien toi da 5 ky tu): ");
    scanf("%s", h.maThiSinh);
    printf("Nhap ten thi sinh (viet lien toi da 30 ky tu): ");
    scanf("%s", h.tenthiSinh);
    printf("Nhap diem toan: ");
    scanf("%lf", &h.diemToan);
    printf("Nhap diem ly: ");
    scanf("%lf", &h.diemLy);
    printf("Nhap diem hoa: ");
    scanf("%lf", &h.diemHoa);
    h.diemTongCong = h.diemToan + h.diemLy + h.diemHoa;
}

void xuatThongTin(ThiSinh h) {
    printf("Thong tin diem thi sinh\n");
    printf("Ten thi sinh: %s\n", h.tenthiSinh);
    printf("Diem toan: %.2lf\n", h.diemToan);
    printf("Diem ly: %.2lf\n", h.diemLy);
    printf("Diem hoa: %.2lf\n", h.diemHoa);
    printf("Diem tong cong: %.2lf\n", h.diemTongCong);
}

int main() {
    ThiSinh h;

    nhapThongTin(h);
    xuatThongTin(h);

    return 0;
}