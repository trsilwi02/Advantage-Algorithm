/*
• Xuất phát từ lời giải rỗng, thuật toán xây dựng
  lời giải của bài toán theo từng bước, ở mỗi bước
  sẽ chọn một phần tử từ tập ứng cử viên và bổ
  sung vào lời giải hiện có
• Hàm Solution(S) nhận biết tính chấp nhận được
  của lời giải S
• Hàm Select(C) chọn từ tập C ứng cử viên có triển
  vọng nhất để bổ sung vào lời giải hiện có
• Hàm Feasible(S ∪ {x}) kiểm tra tính chấp nhận
  được của lời giải bộ S ∪ {x}

  GREEDY(C) { // C: tập ứng cử viên
    S = {}; // lời giải khởi tạo là tập rỗng
    while C not empty and not Solution(S) do {
        x = Select(C);
        C = C \ {x};
        if Feasible(S  {x}) then {
            S = S  {x};
        }
    }
    if Solution(S) then
        return S;
    else return NIL;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

bool Feasible(int crr, int v){
    if (v > crr){
        return false;
    }
    return true;
}

int Select(int i){
    return arr[i];
}

int main(){
    int n, m, sum=0;
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(),arr.end());
    for(auto x:arr)
    {
        sum += n/x;
        n -= n/x*x;
    }
    cout<<sum;
}