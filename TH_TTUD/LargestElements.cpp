#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
vector<int> _max;

void input(){
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    max.resize(n)
}

int build(int id, int left, int right){
    int crrMax = 0;
    int mid = left + (right - left)/2;
    if (left < right){
        build(2*id, left, mid);
        build(2*id+1, mid+1, right);
    }

    crrMax = max(_max[2*id], _max[2*id+1]);
    _max[id] = crrMax;
}

int main(){
    input();
    return 0;
}