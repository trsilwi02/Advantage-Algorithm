#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[25][25];
bool visited[25];
int currLoad = 0;
int crrValue = 0;
int result = 0;
int X[10000001]; //thứ tự đi của xe bus tại vị trí i thì là n

bool check(int v, int k){ // có đón khách hoặc trả khách được không
    if (visited[v]) return false;
    if (v > n){ // không có khách để đón nữa check xem: đã đón khách cần chưa
        if (visited[v-n]) return true;
        else return false;
    } else {
        if (currLoad >= k){ // nếu hiện tại đã full chỗ (không thể đón thêm)
            return false;
        } else{
            return true;
        }
    }
}

void TRY(int k){
    for (int i = 1; i <= 2*n+1; i++){
        if (check(i, k)){
            X[k] = i;
            visited[i] = true;
        }
    }
}

int main(){
    for (int i = 0; i <= 2*n + 1; i++){
        for (int j = 0; j <= 2*n + 1; j++){
            cin >> arr[i][j];
        }
    }
}