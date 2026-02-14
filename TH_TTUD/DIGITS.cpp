#include <bits/stdc++.h>
using namespace std;

int Caculate(vector<int> arr){
    return (1000*arr[0] + 100*arr[1] + 10*arr[2] + 2*arr[3] + 10000*arr[2] + 1000*arr[4] + 100*arr[5] + 10*arr[6]);
}

void backtrack(int pos, vector<int> arr, vector<bool> visited, int sum, int& ans){
    if (pos >= 7){
        if (Caculate(arr) == sum){
            ans++;
        }
        return;
    }

    for (int i = 0; i <= 9; i++){
        if (visited[i]) continue;
        if (pos == 0 && i == 0) continue;
        if (pos == 2 && i == 0) continue;

        visited[i] = true;
        arr[pos] = i;
        backtrack(pos+1, arr, visited, sum, ans);
        visited[i] = false;
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        int ans = 0;
        vector<int> arr(7);
        vector<bool> visited(10, false);
        backtrack(0, arr, visited, tmp, ans);
        cout << ans << endl;
    }
    return 0;
}