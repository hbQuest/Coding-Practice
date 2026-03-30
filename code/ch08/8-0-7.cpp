#include <stdio.h>

struct Ngay {
    int ngay, thang, nam;
};

void nhap(Ngay &n) {
    printf("Nhap ngay: ");
    scanf("%d", &n.ngay);
    printf("Nhap thang: ");
    scanf("%d", &n.thang);
    printf("Nhap nam: ");
    scanf("%d", &n.nam);
}
    
void xuat(Ngay n) {
    printf("%d-%d-%d", n.ngay, n.thang, n.nam);
}   

int main() {
    Ngay n;

    nhap(n);
    xuat(n);

    return 0;
}

