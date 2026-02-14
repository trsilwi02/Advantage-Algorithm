#include <bits/stdc++.h>
using namespace std;

void GenerateArray(int n, vector<int> arr){
    if (arr.size() == n){
        for (int num : arr){
            cout << num;
        }
        cout << endl;
        return;
    }
    else {
        arr.push_back(0);
        GenerateArray(n, arr);
        arr.pop_back();

        if (arr.empty() || arr.back() != 1){
            arr.push_back(1);
            GenerateArray(n, arr);
            arr.pop_back();
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr;
    GenerateArray(n, arr);

    return 0;
}