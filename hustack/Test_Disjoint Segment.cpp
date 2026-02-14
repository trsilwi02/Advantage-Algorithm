#include <bits/stdc++.h>
using namespace std;

/*
__________________________________________

  Tìm lượng lớn nhất đoạn không giao nhau trên đoạn cho trước
__________________________________________
*/

bool compareSegments(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> adj;
    for (int i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj.push_back({tmp1, tmp2});
    }

    sort(adj.begin(), adj.end(), compareSegments);

    int last = -1; // con trỏ để lưu giá trị cuối của mỗi đoạn
    int ans = 0;

    for (int i = 0; i < n; i++){
        if (adj[i].first > last){
            last = adj[i].second;
            ans++;
        }
    }

    cout << ans;
    return 0;
}

// Đel tối ưu 