#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, maxN;
vector<int> arr;

void Input(){
    cin >> n >> a >> b >> c;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
}

void DP(int crr, int crr_ans){
    if (crr == 0){
        maxN = max(maxN, crr_ans);
        return;
    }
    if (crr < 0){
        return;
    }

    for (int i = 0; i < 3; i++){
        DP(crr-arr[i], crr_ans+1);
    }
}

int main(){
    Input();
    DP(n, 0);
    cout << maxN << endl;
    return 0;
}