#include <stdio.h>
#include <math.h>

struct HocSinh {
    char maHS[50];
    char tenHS[100];
    int diem;
};

void docFile(const char* tenFile, HocSinh ds[], int& n) {
    FILE* f = fopen(tenFile, "rt");
    if (f == NULL) {
        printf("Khong mo duoc!");
        return;
    }

    fscanf(f, "%d", &n);

    fgetc(f); // read the \n 

    // for(int i = 0; i < n; i++) {
    //     fscanf(f, "%[^|]|%[^|]|%d", ds[i].maHS, ds[i].tenHS, &ds[i].diem);
    // }
    for(int i = 0; i < n; i++) {
        char c;
        int j = 0;
        while ((c = fgetc(f)) != '|' && c != EOF) {
            ds[i].maHS[j++] = c; 
        }
        ds[i].maHS[j] = '\0';
        
        j=0;
        while ((c = fgetc(f)) != '|' && c != EOF) {
            ds[i].tenHS[j++] = c; 
        }
        ds[i].tenHS[j] = '\0';
        fscanf(f, "%d", &ds[i].diem);
        fgetc(f); // read the \n
    }

    fclose(f);
}

void ghiFile(const char* tenFile, HocSinh ds[], int n) {
    FILE* f = fopen(tenFile, "wt");
    if (f == NULL) {
        printf("Khong mo duoc!");
        return;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 8) {
            count++;
        }
    }

    fprintf(f, "%d\n", count);

    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 8) {
            
            fprintf(f, "%s|%s|%d\n", ds[i].maHS, ds[i].tenHS, ds[i].diem);
        }
    }

    fclose(f);
}

int main() {
    int n = 0;
    HocSinh danhSachHS[100];

    docFile("INPUT.txt", danhSachHS, n);

    if (n > 0) {
        ghiFile("OUTPUT.txt", danhSachHS, n);
        printf("Da ghi xong!");
    }

    // FILE* fp = fopen("OUTPUT1.txt", "w+");
    // fprintf(fp, "0123456789");
    // rewind(fp); // dua con tro ve vi tri dau cua dong dang doc
    // fprintf(fp, "*****");

    return 0;
}