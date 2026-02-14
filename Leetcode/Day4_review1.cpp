#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000+5;
vector<vector<pair<int, int>>> edges(MAXN);

vector<bool> visited;

void input(){
    int n; //  số đỉnh
    cin >> n;
    for (int i = 1; i < n; i++){ // số cạnh = số đỉnh - 1
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
}

void dfs1(int u, int father){
    for (pair<int, int> crr : edges[u])
}

int main(){
    input();
    return 0;
}