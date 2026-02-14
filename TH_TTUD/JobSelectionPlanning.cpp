#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int>& parent, int x){
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> jobs(n);
    int maxd = 0;

    for(int i = 0; i < n; i++){
        cin >> jobs[i].first >> jobs[i].second; // deadline, profit
        maxd = max(maxd, jobs[i].first);
    }

    sort(jobs.begin(), jobs.end(), [&](auto &a, auto &b){
        return a.second > b.second;
    });

    vector<int> parent(maxd+1);
    for (int i = 0; i <= maxd; i++) parent[i] = i;

    long long total = 0;

    for (auto &job : jobs){
        int d = job.first;
        int p = job.second;

        int free_slot = findParent(parent, d);
        if (free_slot > 0){
            total += p;
            parent[free_slot] = free_slot - 1; // chiếm slot này
        }
    }

    cout << total << endl;
}
