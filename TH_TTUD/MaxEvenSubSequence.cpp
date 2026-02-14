#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

void input(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int main(){
    input();
    int best_even = -1, best_odd = -1;
    for (int x : arr){
        if (x % 2 == 0){
            best_even = max(best_even + x, x);
            best_odd = best_odd + x;
        } else {
            int old_even = best_even;
            int old_odd  = best_odd;
            best_even = old_odd + x;
            best_odd = max(old_even + x, x);
        }
    }

    cout << best_even << endl;
    return 0;
}