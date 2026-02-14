#include <bits/stdc++.h>
using namespace std;

int n, c, ans = 0;
vector<int> arr;

bool check(int D){
    int last_position = arr[0];
    int count = 1;

    for (int p : arr){
        if (p - last_position >= D){
            last_position = p;
            count++;
        }
    }

    if (count >= c) return true;
    else return false;
}

void Try(int low, int high){
    if (low >= high) return;
    int mid = low + (high-low)/2;

    if (check(mid)){
        ans = max(ans, mid);
        Try(mid+1, high);
    } else {
        Try(low, mid);
    }
}

int main(){
    cin >> n >> c;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    Try(0, arr[n-1] - arr[0]);

    cout << ans << endl;
    return 0;
}