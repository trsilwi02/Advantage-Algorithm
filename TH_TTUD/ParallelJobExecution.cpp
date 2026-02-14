#include <bits/stdc++.h>
using namespace std;

bool cmd (const int& a, const int& b){
    return a > b;
}

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmd);
    // int previous = arr[0]+1;
    int maxTime = 0;
    for (int i = 0; i < n; i++){
        // if (previous - 1 > arr[i]){
        //     break;
        // }
        maxTime = max(maxTime, arr[i] + i);
        // previous = arr[i];
    }

    cout << maxTime << endl;
    return 0;
}