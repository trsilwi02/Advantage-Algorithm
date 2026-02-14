#include <bits/stdc++.h>
using namespace std;

bool Backtracking(int crr, vector<bool>& visited, vector<int>& path, int n, vector<vector<int>>& adj){ //  crr: đỉnh hiện tại
    if (path.size() == n) {
        for (int neighbor : adj[crr]){
            if (neighbor == path[0]){
                return true;
            }
        }
        return false;
    }
    for (int v : adj[crr]){
        if (!visited[v]){
            visited[v] = true;
            path.push_back(v);
            if (Backtracking(v, visited, path, n, adj)){
                return true;
            }

            visited[v] = false;
            path.pop_back();
        }
    }

    return false;
}my

bool checkHalminton(int n, vector<vector<int>> adj){
    if (n <= 2){
        return false;
    }

    vector<int> path; //biến theo dõi cũng đỉnh đã đi qua
    path.push_back(1);
    vector<bool>visited(n+1, false); //biến theo doi những đỉnh đã thăm
    visited[1] = true;

    return Backtracking(1, visited, path, n, adj);

}

void input() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(m+1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Đồ thị vô hướng
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkHalminton(n, adj)){
        cout << 1 << endl;

    } else {
        cout << 0 << endl;
    }
}

int main(){
    int num;
    cin >> num;
    while(num > 0){
        input();
        num--;
    }

    return 0;
}