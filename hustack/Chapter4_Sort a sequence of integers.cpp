#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int left, int right, int mid){
    vector<int> left_arr;
    vector<int> right_arr;
    for (int i = left; i <= right; i++){
        if (i <= mid){
            left_arr.push_back(arr[i]);
        } else {
            right_arr.push_back(arr[i]);
        }
    }

    int i = 0, j = 0, k = left;

    while (i < left_arr.size() && j < right_arr.size()){
        if (left_arr[i] < right_arr[j]){
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }

    while (i < left_arr.size()){
        arr[k++] = left_arr[i++];
    }

    while (j < right_arr.size()){
        arr[k++] = right_arr[j++];
    }
}

void MergeSort(vector<int> &arr0, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        MergeSort(arr0, left, mid);
        MergeSort(arr0, mid+1, right);
        Merge(arr0, left, right, mid);
    }
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

    MergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}