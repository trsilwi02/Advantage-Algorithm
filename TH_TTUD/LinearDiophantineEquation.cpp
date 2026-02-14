#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<int> arr; // mảng chứa a1, a2, a3...
vector<int> x; // mảng chứa nghiệm hiện tại x1, x2, x3...
long long ans; // đáp án
vector<int> suffix_sum; // mảng để chứa tổng các hệ số phía sau để tính cận

void Try(int k, int crrSum){ // k là index và crrSum là tổng hiện tại tính đc
    if (k == n) {
        if (crrSum == m){
            ans++;
        }
        return;
    }

    int min_suffix = suffix_sum[k+1];

    int remaining = m - crrSum - min_suffix; // phần tổng còn lại có thể sử dụng

    int max_val = remaining / arr[k];

    for (int i = 1; i <= max_val; i++){ // thử từng x
        x[k] = i;
        Try(k+1, crrSum + arr[k] * i);
    }
}

int main(){
    
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    x.resize(n);
    suffix_sum.assign(n+1 ,0);

    for (int i = n - 2; i >= 0; i--){
        suffix_sum[i] = suffix_sum[i+1] + arr[i];
    }

    Try(0, 0); 

    cout << ans << endl;

    return 0;
}