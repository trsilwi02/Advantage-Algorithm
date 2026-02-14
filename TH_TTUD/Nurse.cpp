#include <bits/stdc++.h>
using namespace std;

int n, k1, k2;
vector<char> arr;

int ans = 0;

void input(){
    cin >> n >> k1 >> k2;
    arr.resize(n+1);
}

bool check(int day){ //check hiện tại có thỏa mãn ràng buộc hay không
    int flow = 0;
    if (day == 0) return true;
    for (int i = 1; i <= day; i++){
        if (day == 1 && arr[i] == 'b') return false;
        if (arr[i] == 'b'){
            if (i == 1 || i == n){
                return false;
            }
            if (flow < k1){ //chưa làm đủ thì chưa đc off
                return false;
            }
            flow = 0;
        }
        else {
            if (flow > k2) return false; // đã làm quá nhiều
            flow++;
        }
    }

    return true;
}

void backtrack(int day){
    if (day > n){
        ans++;
        return;
    } 
    day++;
    if (check(day)){ //ngay trc do ma ok thi sang ngay tiep theo
        arr[day] = 'w';
        backtrack(day);
        arr[day] = 'b';
        backtrack(day);
    }
}

int main(){
    input();
    backtrack(0);

    return 0;
}