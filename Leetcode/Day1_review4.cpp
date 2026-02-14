#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int _count = 1;
    for (int i = 1; i < n; i++){
        if (arr[i-1] <= arr[i] && arr[i-1]%2 == arr[i]%2) _count++;
        else _count = 1;
    }

    cout << _count << endl;

    return 0;
}