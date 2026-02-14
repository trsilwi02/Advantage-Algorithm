#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> road;

int n;
int crrCost = 0;
int bestCost = INT_MAX;
int adjmin = INT_MAX;

void input(){
    cin >> n;
    adj.resize(n+1, vector<int>(n+1));
    visited.assign(n+1, false);
    road.resize(n+1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> adj[i][j];
            if (i != j) adjmin = min(adjmin, adj[i][j]);
        }
    }

    visited[1] = true;
    road[1] = 1;
}

void backtrack(int k){
    int newCost = crrCost + (n-k+1) * adjmin;
    if (newCost >= bestCost) return;

    if (k == n){
        crrCost += adj[road[k-1]][1];
        bestCost = min(bestCost, crrCost);
        return;
    }

    for (int v = 2; v <= n; v++){
        if (!visited[v]){
            road[k] = v;
            visited[v] = true;
            crrCost += adj[road[k-1]][v];

            backtrack(k+1);

            visited[v] = false;
            crrCost -= adj[road[k-1]][v];
        }
    }
}

int main(){
    input();

    backtrack(2);

    cout << bestCost << endl;

    return 0;
}