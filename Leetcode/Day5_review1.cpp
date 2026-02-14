#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<int> arr;
int n, q;

void input(){
    cin >> n >> q;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    tree.resize(4*n+1);
}

void build(int id, int l, int r){
    if (l == r){
        tree[id] = arr[l];
        return;
    }
    int mid = l+((r-l)/2);
    build (2*id,l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = tree[2*id] + tree[2*id+1];
}

void update(int id, int l, int r, int pos, int val){ // giống build nhưng thêm ràng buộc pos nằm giữa l và r
    if (pos > r || pos < l) return;
    if (l == r){
        tree[id] = val;;
        return;
    }
    int mid = l + ((r-l)/2);
    update (2*id, l, mid, pos, val);
    update (2*id+1, mid+1, r, pos, val);

    tree[id] = tree[2*id] + tree[2*id+1];
}

int getSum(int id, int l, int r, int L, int R){
    if (L > r || R < l) return 0;
    if (L <= l && R >= r) return tree[id];

    int mid = l + ((r-l)/2);

    int getSum1 = getSum(2*id, l, mid, L, R);
    int getSum2 = getSum(2*id+1, mid+1, r, L, R);

    return getSum1 + getSum2;
}

int main(){
    input();
    build(1, 1, n);
    while (q--){
        int tmp;
        cin >> tmp;
        if (tmp ==  1){
            int pos, val;
            cin >> pos >> val;
            update(1,1,n,pos, val);
        } else {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            cout << getSum(1,1,n, tmp1, tmp2) << endl;
        }
    }
    return 0;
}