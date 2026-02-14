#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int endNode;
    long long value;
} 

struct cmp{
    bool operator()(const vector<pair<int, int>> &a,const vector<int, int>> &b){
        return a.second > b.second;
    }
}

void Dijkstra(int start, int end, vector<<vector<Edge>> adj, int n){
    vector<long long> d(n+1, LLONG_MAX);
    d[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;
    queue.push({0, start});

    while (!queue.empty()){
        long long crrcost = queue.top().first;
        int crr = queue.top().second; 
        queue.pop();

        if (crrNode == end){
            return d[end];
        }

        if (crrCost > d[crr]){
            continue;
        }

        for (auto edge : adj[crrNode]){
            int v = edge.endNode;
            long long weight = edge.value;

            if (d[crr] + weight < d[v]){
                d[v] = d[crr] + weight;
                queue.push({d[v], v});
            }
        }
    }

    return (d[end] == LLONG_MAX) ? -1 : d[end];
}

int main(){

}