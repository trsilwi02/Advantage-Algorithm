#include <bits/stdc++.h>
using namespace std;

bool cmd (const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        arr.push_back({tmp1, tmp2});
    }

    sort(arr.begin(), arr.end(), cmd);

    int last_end = arr[0]. second;
    int dem = 1;

    for (int i = 1; i < n; i++){
        if (last_end < arr[i].first){
            last_end = arr[i].second;
            dem++;
        }
    }

    cout << dem << endl;
    return 0;
}