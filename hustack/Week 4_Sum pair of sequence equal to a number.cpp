#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    int count = 0;
    int r = n-1, l = 0;
    while(l < r){
        if (arr[r] + arr[l] > q){
            r--;
        } else if (arr[r] + arr[l] < q){
            l++;
        } else {
            count++;
            r--;
            l++;
        }
    }
    cout << count;
    return 0;
}