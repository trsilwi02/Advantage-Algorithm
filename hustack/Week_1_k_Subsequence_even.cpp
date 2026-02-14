#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int count = 0;
    int p = 0;
    while (p + k - 1 < n){
        int sum = 0;
        for (int i = p; i < p+k; i++){
            sum += arr[i];
        }
        if (sum % 2 == 0) count++;
        p++;
    }

    cout << count;

    return 0;
}