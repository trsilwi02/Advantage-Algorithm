// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> adj;
// int n, m;
// vector<bool> visited(n+1, false);
// stack<int> st;

// void input(){
//     cin >> n >> m;
//     adj.resize(n+1);   
//     visited.resize(n+1, false);
//     for (int i = 0; i < m; i++){
//         int tmp1, tmp2;
//         cin >> tmp1 >> tmp2;
//         adj[tmp1].push_back(tmp2);
//         adj[tmp2].push_back(tmp1);
//     }

//     for (int i = 1; i <= n; i++) {
//         sort(adj[i].begin(), adj[i].end());
//     }
// }

// int main(){
//     input();
//     visited[1] = true;
//     st.push(1);
//     while (!st.empty()){
//         int crr = st.top();
//         st.pop();
//         cout << crr << " ";

//         for (int i = adj[crr].size() - 1; i >= 0; i--){
//             if(!visited[adj[crr][i]]){
//                 visited[adj[crr][i]] = true;
//                 st.push(adj[crr][i]);
//             }
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> result;

void dfs(int u) {
    visited[u] = true;
    result.push_back(u);
    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Đọc các cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Sắp xếp các danh sách kề để đảm bảo duyệt theo thứ tự từ điển
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // Gọi DFS bắt đầu từ đỉnh 1
    dfs(1);

    // In ra thứ tự duyệt DFS
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i + 1 < (int)result.size()) cout << " ";
    }

    cout << "\n";
    return 0;
}
