#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000000;
int n, cot[maxN], ans = 0; //x: lưu giá trị (có thể kh cần), cot[]: lưu vị trí của từng cột

bool check(int v, int k){
    for (int i = 0; i < k; i++){
        if (cot[i] == v){
            return false;
        }
        if (abs(k-i) == abs(v-cot[i])){
            return false;
        }
    }

    return true;
}

void Try(int k){
    for (int v = 1; v <= n; v++){
        if (check(v, k)){
            cot[k] = v;
            
            if (k >= n-1){
                ans++;
            }

            else {
                Try(k+1);
            }
            cot[k] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try(0);
    cout << ans;
    return 0;
}