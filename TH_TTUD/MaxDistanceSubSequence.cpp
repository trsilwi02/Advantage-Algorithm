#include <bits/stdc++.h>
using namespace std;

bool cmd(const int &a, const int &b){
    return a < b;
}

bool checkDistand(int distand, int n, int v, vector<int> arr){
    int count_cow = 1;
    int crr_cow = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] - crr_cow >= distand){
            count_cow++;
            crr_cow = arr[i];
        }
    }
    if (count_cow >= v){ // khoảng cách này ổn thì trả về true(tăng)
        return true;
    } else {
        return false;
    }
}

int solve(vector<int> arr, int m, int v){
    sort(arr.begin(), arr.end(), cmd);
    int low = 1;
    int high = arr[m-1] - arr[0];
    int ans = 1;
    while (low < high){
        int mid = low + (high-low)/2;
        if (checkDistand(mid, m, v, arr)){
            ans = mid;
            low = mid+1;
        } else {
            high = mid;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        vector<int> arr;
        arr.resize(m);
        for (int j = 0; j < m; j++){
            cin >> arr[j];
        }
        cout << solve(arr, m, v) << endl;
    }
}