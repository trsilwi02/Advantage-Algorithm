#include <bits/stdc++.h>
using namespace std;

// build -> truy vấn
vector<int> arr;
vector<pair<int, int>> query;
int n, q;

vector<int> buildedMin, buildedMax;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    cin >> q;
    for (int i = 0; i < q; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        query.push_back({tmp1, tmp2});
    }

    buildedMin.assign(4*n+1, INT_MAX);
    buildedMax.assign(4*n+1, 0);
}

void buildMin(int id, int left, int right){
    if (left >= right) {
        buildedMin[id] = arr[left];
        return;
    }
    int mid = left + (right-left)/2;
    buildMin(2*id, left, mid);
    buildMin(2*id+1, mid+1, right);

    buildedMin[id] = min(buildedMin[2*id], buildedMin[2*id+1]);
}

void buildMax(int id, int left, int right){
    if (left >= right) {
        buildedMax[id] = arr[left];
        return;
    }
    int mid = left + (right-left)/2;
    buildMax(2*id, left, mid);
    buildMax(2*id+1, mid+1, right);

    buildedMax[id] = max(buildedMax[2*id], buildedMax[2*id+1]);
}

int queryMin(int id, int l, int r, int L, int R){
    if (L > r || R < l){
        return INT_MAX;
    } 
    if (L <= l && R >= r){
        return buildedMin[id];
    }

    int mid = l + (r-l)/2;
    int minLeft = queryMin(2*id, l, mid, L, R);
    int minRight = queryMin(2*id+1, mid+1, r, L, R);

    return min(minLeft, minRight);
}

int queryMax(int id, int l, int r, int L, int R){
    if (L > r || R < l){
        return INT_MIN;
    } 
    if (L <= l && R >= r){
        return buildedMax[id];
    }

    int mid = l + (r-l)/2;
    int maxLeft = queryMax(2*id, l, mid, L, R);
    int maxRight = queryMax(2*id+1, mid+1, r, L, R);

    return max(maxLeft, maxRight);
}

int solve(int left, int right){

    return queryMax(1, 0, n-1, left, right) - queryMin(1, 0, n-1, left, right);
}

int main() {
    input();

    buildMin(1, 0, n-1);
    buildMax(1, 0, n-1);

    for (int i = 0; i < q; i++){
        cout << solve(query[i].first, query[i].second) << endl;
    }

    return 0;
}