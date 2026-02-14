#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tree;

void build(int left, int right, int node){
    if (left >= right) {
        tree[node] = arr[left];
    } else {
        int mid = (left + right) / 2;
        build(left, mid, 2*node);
        build(mid+1, right, 2*node+1);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int querry(int l, int r, int L, int R, int node) // truy van
{
    if (L > r || R < l) return INT_MAX;
    if (l >= L && r <= R) return tree[node];
    else {
        int mid = (l+r)/2;
        return min(querry(l, mid, L, R, 2*node), querry(mid+1, r, L, R, 2*node+1));
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    tree.resize(4*n+1);
    build(0, n-1, 1);
    int m;
    cin >> m;
    int sum = 0;
    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int tmp = querry(0, n-1, tmp1, tmp2, 1);
        sum  += tmp;
    }

    cout << sum;
    return 0;
}