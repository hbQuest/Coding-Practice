#include <stdio.h>
#define MAXSOHOCSINH 51
#define MAXTEN 31

struct danhSach {
    char tenHocSinh[MAXTEN];
};

struct LopHoc {
    char tenLop[MAXTEN];
    unsigned int siSo;
    danhSach hocSinh[MAXSOHOCSINH];
};

void nhapDanhSach(danhSach h[], int n) {
    printf("Nhap ten hoc sinh (viet lien toi da 30 ky tu)\n");
    for (int i = 0; i < n; i++) {
        printf("Ten hoc sinh %d: ", i+1);
        scanf("%s", h[i].tenHocSinh);
    }
}

void xuatDanhSach(danhSach h[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Hoc sinh %d: %s\n", i+1, h[i].tenHocSinh);
    }
}

void nhapThongTin(LopHoc& l) {
    printf("Nhap ten lop (viet lien toi da 30 ky tu): ");
    scanf("%s", l.tenLop);
    printf("Nhap si so: ");
    scanf("%d", &l.siSo);
    printf("Nhap danh sach hoc sinh\n");
    nhapDanhSach(l.hocSinh, l.siSo);
}

void xuatThongTin(LopHoc l) {
    printf("Thong tin lop hoc\n");
    printf("Ten lop: %s\n", l.tenLop);
    printf("Si so: %d\n", l.siSo);
    printf("Danh sach cac hoc sinh\n");
    xuatDanhSach(l.hocSinh, l.siSo);
}

int main() {
    LopHoc lop;

    nhapThongTin(lop);
    xuatThongTin(lop);

    return 0;
}