#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> subArr;
vector<vector<bool>> conflicts;

vector<vector<int>> adj; //không gian lời giải

int best = INT_MAX;

void input(){
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        int subNum;
        cin >> subNum;
        vector<int> subjects(subNum);
        for (int j = 0; j < subNum; j++){
            cin >> subjects[j];
        }
        subArr.push_back(subjects);
    }

    conflicts.assign(m+1, vector<bool>(m+1, false));
    adj.resize(n);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        conflicts[tmp1][tmp2] = true;
        conflicts[tmp2][tmp1] = true;
    }
}

bool canAssign(int course, int teacher){
    bool ok = false;
    for (int sub : subArr[teacher]){
        if (sub == course) ok = true;
    }

    if (!ok) return false;

    for (int sub : adj[teacher]){
        if (conflicts[sub][course]) return false;
    }

    return true;
}

int crrMaxLoad(){
    int crrLoad = 0;
    for (int i = 0; i < n; i++){
        int x = adj[i].size();
        crrLoad = max(crrLoad, x);
    }
    return crrLoad;
}

void backtrack(int k){
    int crrAns = crrMaxLoad();

    if (crrAns > best){
        return;
    }

    if (k > m){
        best = min(crrAns, best);
        return;
    }

    for (int v = 0; v < n; v++){
        if (canAssign(k, v)){
            adj[v].push_back(k);

            backtrack(k+1);

            adj[v].pop_back();
        }
    }
}

int main(){
    input();

    backtrack(1);

    cout << best << endl;

    return 0;
}