#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int soAm = 0;
    double tongDuong = 0;
    int soDuong = 0;
    double tongAm = 0;
    for (int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp >= 0){
            soDuong++;
            tongDuong += tmp;
        } else {
            soAm++;
            tongAm += tmp;
        }
    }

    if (soAm != 0){
        printf("%6f ", tongAm/soAm);
    }
    else {
        printf("Mang khong co so am ");
    }

    if (soDuong != 0){
        printf("%6f ", tongDuong);
    } else {
        printf("Mang khong co so duong");
    }

    return 0;
}