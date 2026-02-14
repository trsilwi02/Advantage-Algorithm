#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int endNode;
    long long value;
};

struct Node {
    long long cost;
    int from;
};

struct cmp{
    bool operator()(const Node &a, const Node &b){
        return a.cost > b.cost;
    }
};

long long Dijkstra(int startNode, int endNode, vector<vector<Edge>> adj, int n){
    vector<long long> d(n+1, LLONG_MAX);
    d[startNode] = 0;

    // Hàng đợi ưu tiên
    priority_queue<Node, vector<Node>, cmp> queue;
    queue.push({0, startNode});

    while (!queue.empty()){
        long long crrCost = queue.top().cost;
        int crrNode = queue.top().from;
        queue.pop();

        if (crrNode == endNode){
            return d[endNode];
        }

        if (crrCost > d[crrNode]){
            continue;
        }

        for (auto edge : adj[crrNode]){
            int v = edge.endNode;
            long long weight = edge.value;

            // nếu tìm thấy đường đi ngắn hơn đến v qua crrNode
            if (d[crrNode] + weight < d[v]){
                d[v] = d[crrNode] + weight;
                queue.push({d[v], v});
            }
        }
    }
    return (d[endNode] == LLONG_MAX) ? -1 : d[endNode];
}

int main(){
    // Input
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n+1);
    for (int i = 0; i < m; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].push_back({tmp2, tmp3});
    }

    int begin, end;
    cin >> begin >> end;

    cout << Dijkstra(begin, end, adj, n) << endl;
    return 0;
}