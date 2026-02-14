#include <bits/stdc++.h>
using namespace std;

int n;
int a[99999];
bool used[99999];

void TRY(int k){
    if (k > n) {
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= n; i++){
            if (!used[i]){
                a[k] = i;
                used[i] = true;
                TRY(k+1);
                used[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    TRY(1);

    return 0;
}