#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long ans = 0;

void Merge(vector<int>& arr, vector<int>& temp, int left, int right){
    if(left >= right) return;
    int mid= (left+right)/2;
    Merge(arr, temp, left, mid);
    Merge(arr, temp, mid+1, right);

    int i = left, j = mid+1, k = left;// i là trái và j sẽ là phải
    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            ans += (mid-i+1); // nếu phải nhỏ hơn thì sẽ nhỏ hơn hết tất cả các phần tử còn lại trong temp
            ans %= MOD;
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    } 
    while (j <= right){
        temp[k++] = arr[j++];
    }

    // for (int v = left; v <= right; v++){ //Sắp xếp lại arr
    //     arr[v] = temp[v];
    // }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    vector<int> temp(n);
    Merge(arr, temp, 0, n-1);
    cout << ans << endl;

    for (auto i : arr){
        cout << i << " ";
    }

    return 0;
}