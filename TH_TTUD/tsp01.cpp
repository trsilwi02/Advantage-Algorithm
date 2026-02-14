// #include <bits/stdc++.h>
// using namespace std;

// int n, crrValue = 0, ans = INT_MAX;
// vector<vector<int>> adj;
// vector<bool> visited;

// void input(){
//     cin >> n;
//     adj.resize(n, vector<int>(n));
//     visited.assign(n, false);
//     for(int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             cin >> adj[i][j];
//         }
//     }
// }

// void backtrack(int u, int _count){
//     if (_count == n){
//         ans = min(ans, crrValue + adj[u][0]);
//         return;
//     }

//     for (int v = 1; v < n; v++){
//         if(!visited[v]){
//             visited[v] = true;
//             crrValue += adj[u][v];

//             backtrack(v, _count + 1);

//             visited[v] = false;
//             crrValue -= adj[u][v];
//         }
//     }
// }

// int main(){
//     input();
//     visited[0] = true;
//     backtrack(0, 1);

//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<int>> dp;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    int full = 1 << n;
    const int INF = INT_MAX;
    dp.resize(full, vector<int>(n, INF));

    dp[1][0] = 0; // bắt đầu tại thành phố 0

    for (int mask = 1; mask < full; mask++){
        for (int u = 0; u < n; u++){
            if ((mask & (1 << u)) == 0) continue;  // không nằm trong tập hợp ĐÃ ĐI QUA
            if (dp[mask][u] == INF) continue; // trạng thái này chưa bao giờ được cập nhật

            for (int v = 0; v < n; v++){
                if ((mask & (1 << v)) != 0) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = min (dp[newMask][v], dp[mask][u] + adj[u][v]);
            }
        }
    }

    int ans = INF;
    for (int u = 0; u < n; u++){
        ans = min(ans, dp[full-1][u] + adj[u][0]);
    }

    cout  << ans << endl;
    return 0;
}