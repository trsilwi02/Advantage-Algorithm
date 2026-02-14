// Đề bài:
// Bạn có một tấm gỗ lớn kích thước $W=4, H=5$ (Diện tích tổng = 20).
// Bạn cần cắt các miếng gỗ nhỏ hơn từ danh sách sau để đạt Tổng Diện Tích Sử Dụng lớn nhất.

#include <bits/stdc++.h>
using namespace std;

int w, h, n;
vector<pair<int, int>> items;
vector<bool> used;

int crrArea = 0;

int maxArea = 0;

bool cmd(const pair<int, int> &a, const pair<int, int> &b){
    return a.first*a.second > b.first*b.second;
}


void input(){
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        items.push_back({tmp1, tmp2});
    }

    sort(items.begin(), items.end(), cmd);
    used.assign(n+1, false);
}

bool check(int w, int h, int W, int H){ // với w, h là của đang xét chi tiết và W, H là phần tấm gỗ
    if (w > W || h > H) return false;
    return true;
}

void Backtrack(int W, int H){
    // cập nhật thằng lớn nhất
    if (crrArea > maxArea){
        maxArea = crrArea;
    }

    // phần nhánh cận
    int potential = 0;
    for (int i = 0; i < n; i++){
        if (!used[i]) potential += items[i].first* items[i].second;
    }
    if (crrArea + potential <= maxArea) return; //nếu những cái còn lại + hiện tại mà đã < maxArea rồi thì nhót thôi
    
    // phần thử các điều kiện và đệ quy
    for (int i = 0; i < n; i++){
        if (!used[i]){
            if (check(items[i].first, items[i].second, W, H)){ // đặt được con vợ này vào
                used[i] = true;
                crrArea += items[i].first * items[i].second;
                Backtrack(W, H - items[i].second);
                Backtrack(W - items[i].first, H);

                // quay lui lại
                used[i] = false;
                crrArea -= items[i].first * items[i].second;
            }
        }
    }
}



int main(){
    input();
    Backtrack(w, h);

    cout << maxArea << endl;
    return 0;
}