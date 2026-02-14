#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

vector<int> lowerArr;

// sử dụng hàm sẵn lower_bound (tìm kiếm nhị phân) -> trả lại vị trí cần tìm

void input(){
    cin >> n;
    arr.resize(n);
    for(int  i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void updateArr(int x){
    auto p = lower_bound(lowerArr.begin(), lowerArr.end(), x); //vị trí p của số x
    if (p == lowerArr.end()) { //đi đến cuối và kh tìm thấy
        lowerArr.push_back(x);
    }
    else{
        *p = x; // thay thế
    } 
}

int main(){
    input();
    for (int x : arr){
        updateArr(x);
    }

    cout << lowerArr.size() << endl;
    return 0;
}