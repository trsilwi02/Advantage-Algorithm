#include <bits/stdc++.h>
using namespace std;

int n;
const int N_MAX = 1000005;
int arr[N_MAX];
int temp[N_MAX];


void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

long long Merge(int left, int right, int mid){
    int i = left, j = mid+1, k = left;
    long long inversion_count = 0;
    while(i <= mid && j <= right){
        if (arr[i] > arr[j]){
            temp[k++] = arr[j++];
            inversion_count += (mid-i)+1;
        } else {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }

    for (int v = left; v <= right; v++){
        arr[v] = temp[v];
    }

    return inversion_count;
}

long long Detach(int left, int right){
    long long inversion_count = 0;
    if (left >= right) return 0;
    int mid = left + (right-left)/2;
    inversion_count += Detach(left, mid);
    inversion_count += Detach(mid+1, right);
    inversion_count += Merge(left, right, mid);

    return inversion_count;
}

int main(){
    input();
    cout << Detach(0, n-1) << endl;
    return 0;
}