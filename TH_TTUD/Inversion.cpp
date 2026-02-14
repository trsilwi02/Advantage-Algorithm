#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> temp;
int n, dem = 0;

void mergeSort(int left, int right){
    if(right <= left) return;
    int mid = left + (right-left)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);

    int i = left, j = mid+1, k = left;
    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            dem += mid-i + 1;
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){  //bên trái ko còn gì nên không cần đếm nữa (không có phép so sánh)
        temp[k++] = arr[j++];
        // dem++;
    }

    for (int v = left; v <= right; v++){
        arr[v] = temp[v];
    }
}

int main(){
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    temp.resize(n+1);
    mergeSort(0, n-1);

    cout << dem << endl;

    return 0;
}