#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;

vector<pair<int, int>> orders;
vector<int> status;

int crrVal = 0;
int minVal = INT_MAX;

void input(){
    cin >> n >> k;
    adj.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> adj[i][j];
        }
    }
    orders.resize(k+1);
    for (int i = 1; i <= k; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        orders[i] = {tmp1, tmp2};
    }
    status.assign(k+1, 0);
}

void backtrack(int node, int _count){
    if (crrVal >= minVal) return;

    if (_count == 2*k){
        int total = crrVal + adj[node][1];
        if (total < minVal) minVal = total;
        return;
    }

    for (int i = 1; i <= k; i++){
        if (status[i] == 0){
            int nextNode = orders[i].first;

            crrVal += adj[node][nextNode];
            status[i] = 1;

            backtrack(nextNode, _count+1);

            status[i] = 0;
            crrVal -= adj[node][nextNode];

        } else if(status[i] == 1) {
            int nextNode = orders[i].second;

            crrVal += adj[node][nextNode];
            status[i] = 2;

            backtrack(nextNode, _count+1);

            crrVal -= adj[node][nextNode];
            status[i] = 1;
        }
    }
}

int main(){
    input();

    backtrack(1, 0);

    cout << minVal << endl;
    return 0;
}