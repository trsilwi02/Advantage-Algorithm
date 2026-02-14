#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count_ans = 0;
    for (int i = 1; i <= n; i++){
        if (arr[i-1] > arr[i]){
            count_ans++;
        }
    }

    cout << count_ans << endl;
}