#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
set<long long> visited;
priority_queue<long long, vector<long long>, greater<long long>> pq_min_max;

void Input(){
    arr.push_back(1);
}

void TinhToan(int i){
    if (visited.find(arr[i]*2) == visited.end()){
        pq_min_max.push(arr[i]*2);
        visited.insert(arr[i]*2);
    }
    if (visited.find(arr[i]*3) == visited.end()){
        pq_min_max.push(arr[i]*3);
        visited.insert(arr[i]*3);
    }
    if (visited.find(arr[i]*5) == visited.end()){
        pq_min_max.push(arr[i]*5);
        visited.insert(arr[i]*5);
    }
}

int UglyNumber(int n){
    Input();
    int num = 0;
    while (num < n){
        TinhToan(num);
        arr.push_back(pq_min_max.top());
        pq_min_max.pop();
        num++;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return arr[n-1];
}



int main(){
    int n;
    cin >> n;
    // visited.assign(2*n + 1, false);
    cout << UglyNumber(n) << endl;
    return 0;
}