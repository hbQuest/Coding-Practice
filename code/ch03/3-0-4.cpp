#include <stdio.h>
#include <conio.h>

void xemQuy(int a){
    switch (a){
        case 1: case 2: case 3: 
            printf("Thang thuoc quy 1");
            break;
        case 4: case 5: case 6:
            printf("Thang thuoc quy 2");
            break;
        case 7: case 8: case 9:
            printf("Thang thuoc quy 3");
            break;
        case 10: case 11: case 12:
            printf("Thang thuoc quy 4");
            break;
    }
}

int main() {
    int a;
    do {
        printf("Nhap thang (1 den 12): ");
        scanf("%d", &a);
        if (a < 1 || a > 12) {
            printf("Nhap lai!\n");
        }
    } while (a < 1 || a > 12);

    xemQuy(a);

    return 0;
}
