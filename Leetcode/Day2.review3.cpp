#include <bits/stdc++.h>
using namespace std;

void Gop(vector<int> arr, int timee){
    if (arr.size() <= 2) {
        cout << timee << endl;
        return;
    }
    int n = arr.size();
    if (n % 2 != 0) {
        n++;
        arr.push_back(0);
    }
    vector<int> newArr;
    for (int i = 1; i < n; i++){
        if (i % 2 != 0){
            int x = arr[i-1] + arr[i];
            newArr.push_back(x);
            timee += x;
        }
    }
    Gop(newArr, timee);
}

int main(){
    int t;
    cin >> t;

    while (t > 0){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        Gop(arr, 0);
        t--;
    }

    return 0;
}
