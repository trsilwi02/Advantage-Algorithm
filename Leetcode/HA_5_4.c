#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if (n< 2 || n > 10){
        printf("0");
        return 0;
    }

    int arr[99999];
    long long tong = -999999;
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if (i != 0){
            int tmp = arr[i-1] + arr[i];
            if (tmp > tong){
                tong = tmp;
            }
        }
    }

    printf("%lld", tong);
    return 0;
}