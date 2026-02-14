#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];        // mảng đầu vào
int st[4*N];     // cây phân đoạn lưu chỉ số của phần tử nhỏ nhất
int n;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = l;  // lưu chỉ số phần tử
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    // chọn chỉ số có giá trị nhỏ hơn
    if (a[st[id*2]] < a[st[id*2+1]])
        st[id] = st[id*2];
    else
        st[id] = st[id*2+1];
}

// query chỉ số nhỏ nhất trong đoạn [u, v]
int getMin(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -1; // ngoài đoạn
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    int left = getMin(id*2, l, mid, u, v);
    int right = getMin(id*2+1, mid+1, r, u, v);

    if (left == -1) return right;
    if (right == -1) return left;
    return (a[left] < a[right]) ? left : right;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);

    int q; 
    cin >> q;
    int ans = 0;
    while (q--) {
        int l, r; cin >> l >> r;
        int idx = getMin(1, 0, n-1, l, r);
        ans += a[idx];
    }

    cout << ans;

    return 0;
}
