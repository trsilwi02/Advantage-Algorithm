#include <bits/stdc++.h>
using namespace std;

bool cmd (const int& a, const int& b){
    return a < b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n ; i++){
        int tmp = 0;
        cin >> tmp;
        arr1.push_back(tmp);
    }
    arr2.resize(m);
    for (int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end(), cmd);
    sort(arr2.begin(), arr2.end(), cmd);

    int i = 0, j = 0;
    int count_ans = 0;
    while (i < n || j < m){
        if (arr1[i] == arr2[j]){
            count_ans++;
            i++;
            j++;
        } else if (arr1[i] > arr2[j]){
            j++;
        } else {
            i++;
        }
    }
    cout << count_ans << endl;
    return 0;
}