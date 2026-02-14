#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int a[maxN], n, m, M[maxN][30];

void buildM(){
    for (int i = 0; i < n; i++){
        M[i][0] = i;
    }

    for (int j = 1; (1<<j) <= n; j++){
        for (int i = 0; i + (1<<j)-1 < n; i++){
            if (a[M[i][j-1]] < a[M[i+(1<<(j-1))][j-1]]){
                M[i][j] = M[i][j-1];
            } else {
                M[i][j] = M[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int rmq(int i, int j){
    int k = log2(j-i+1);
    return min(a[M[i][k]], a[M[j-(1<<k)+1][k]]);
}

int main(int argc, char const *argv[]){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    buildM();

    cin >> m;
    int sum = 0 ;
    for (int i=0; i<m; i++){
        int l, r;
        cin >> l >> r;

        sum += rmq(l, r);
    }

    cout << sum;
    return 0;
}