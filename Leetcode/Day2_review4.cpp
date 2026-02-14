#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> arr;
vector<vector<int>> adj;

vector<bool> visited; //vì khi đến lấy hàng rồi thì không cần thiết phải quay lại lấy lần nữa
vector<int> road; // duong di

vector<int> bestRoad;

int crr = 0;
int best = INT_MAX;

int crrQ = 0;

void input(){
    cin >> n >> q;

    arr.resize(n+1);
    adj.resize(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i <= n; i ++){
        for (int j = 0; j <= n; j++){
            cin >> adj[i][j];
        }
    }

    visited.assign(n+1, false);
    road.assign(n+2, 0);
}

void backtrack(int k){ // di den diem thu k
    if (crrQ >= q){
        crr += adj[road[k-1]][0];
        if (best > crr){
            best = crr;
            bestRoad = road;
        }
        crr -= adj[road[k-1]][0];
        return;
    }

    if (k == n){
        return;
    }

    for (int v = 1; v <= n; v++){
        if (!visited[v]){
            road[k] = v;
            visited[v] = true;
            crrQ += arr[v];
            crr += adj[road[k-1]][v];

            backtrack(k+1);

            visited[v] = false;
            crrQ -= arr[v];
            crr -= adj[road[k-1]][v];
        }
    }

    return;
}

int main(){
    input();

    visited[0] = true;
    road[0] = 0;

    backtrack(1);

    cout << best << endl;

    int citys = 0;
    for (int v : bestRoad){
        if (v != 0) citys++;
    }

    cout << citys << endl;

    for (int i = 1; i < bestRoad.size(); i++){
        if (bestRoad[i] == 0) break;
        cout << bestRoad[i] << " ";
    }

    return 0;
}