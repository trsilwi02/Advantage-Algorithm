/*
    Dãy con tăng liên tiếp dài nhất
    Cho một dãy gồm nsố nguyên a1, a2, . . . , an.
    Input
        •Dòng 1: Số nguyên n(1 ≤n≤105)
        •Dòng 2: nsố nguyên a1, a2, . . . , an
    Output
        •In ra một số nguyên duy nhất là độ dài lớn nhất của dãy con tăng liên tiếp.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int countUp = 1;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int tmpCount = 1;
    for (int i = 1; i < n; i++){
        if (arr[i] >= arr[i-1]){
            tmpCount++;
            countUp = max(countUp, tmpCount);
        } else {
            tmpCount=1;
        }
    }

    cout << countUp << endl;
    return 0;
}