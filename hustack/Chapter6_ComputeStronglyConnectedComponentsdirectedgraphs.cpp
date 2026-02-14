#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node, index;
};

int n, m;
vector<vector<int>> adj;
stack<Node> DFSst; // st[i].first -> crr node, st[i].second -> thứ tự của đỉnh khi duyệt

vector<int> dfsn;
vector<int> low;
stack<int> SCCst;

vector<bool> inStack;

int timee = 0;
int sccCount = 0;

void input(){
    cin >> n >> m;
    adj.resize(n+1);

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
    }

    dfsn.assign(n+1, 0);
    low.assign(n+1, 0);

    inStack.assign(n+1, false);
}

void dfs(int start){
    DFSst.push({start, 0});

    while(!DFSst.empty()){
        int u = DFSst.top().node;
        int &i = DFSst.top().index;

        if (dfsn[u] == 0){ // nếu u chưa đc thăm thì gán dfsn và low, đẩy u vào stack, đánh dấu đã trong stack
            timee ++;
            dfsn[u] = low[u] = timee;
            SCCst.push(u);
            inStack[u] = true;
        }

        if (i < adj[u].size()){
            int v = adj[u][i];
            DFSst.top().index++; // chuyển sang đỉnh tiếp theo

            if (dfsn[v] == 0){
                DFSst.push({v, 0});
            } else if (inStack[v]) {
                low[u] = min(low[u], dfsn[v]);
            }
        } 
            
        else {
            DFSst.pop();
            if (!DFSst.empty()){
                int parent = DFSst.top().node;
                low[parent] = min(low[parent], low[u]);
            }

            if (low[u] == dfsn[u]){
                sccCount++;
                while(true){
                    int tmp = SCCst.top();
                    SCCst.pop();
                    inStack[tmp] = false;
                    if (tmp == u) break;
                }
            }
        }
        
    }
}

int main(){
    input();

    for (int i = 1; i <= n; i++){
        if (dfsn[i] == 0){
            dfs(i);
        }
    }

    cout << sccCount << endl;

    return 0;
}