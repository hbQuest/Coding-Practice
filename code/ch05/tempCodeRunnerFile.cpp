int DemMangConTangDoDaiLonHon1(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            dem++;
        }
    }
    return dem;
}