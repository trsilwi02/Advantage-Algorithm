#include <stdio.h>
#include <math.h>

void TinhHieu(int a,int b)
{
    int Hieu=a-b;
    printf("%d",Hieu);

}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    TinhHieu(a,b);

    return 0;
}