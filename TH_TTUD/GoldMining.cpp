#include <bits/stdc++.h>
using namespace std;

int n, d1, d2, ans = 0;
vector<int> arr;
vector<int> dp;
priority_queue<pair<int, int>> pq;

void input(){
    cin >> n >> d1 >> d2;
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void solve(){
    for (int i = 0; i < n; i++){
        int k = i - d1;
        if (k >= 0) {
            pq.push({dp[k], k});
        }
        int min_k = i - d2;
        while (!pq.empty() && (pq.top().second < min_k)){
            pq.pop();
        }

        if (pq.empty()){
            dp[i] = arr[i];
        }
        else {
            dp[i] = arr[i] + pq.top().first;
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return;
}

int main(){
    input();
    solve();
    return 0;
}