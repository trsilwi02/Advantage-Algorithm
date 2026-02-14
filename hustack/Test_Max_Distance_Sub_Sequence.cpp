#include <bits/stdc++.h>
using namespace std;

int n, m, T;
vector<int> arr;

void Input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

bool Check(int d){ //d là khoảng cách mong đợi 
    int nb = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] - last >= d){ // thì ok
            last = arr[i];
            nb++;
            if (nb >= m){
                break;
            }
        }
    }

    return nb >= m;
}

int Find_D(){// l & r là khoảng cách của trái và phải không phải lưu chỉ số trong arr
    int l = 1;
    int r = (arr[n-1] - arr[0]) / (m-1);

    while (l < r){
        int mid = (l+r+1) / 2;
        if(Check(mid)){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    cin >> T;
    for (int i = 0; i < T; i++){
        Input();
        sort(arr.begin(), arr.end());
        cout << Find_D() << endl;
        arr.clear();
    }

    return 0;

}