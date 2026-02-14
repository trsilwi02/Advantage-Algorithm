#include <bits/stdc++.h>
using namespace std;

int n;
int res = 1;

vector<int> arr;
vector<int> lis;// chứa dãy con tăng dài nhất với lis[i] là dãy con tăng dài nhất kết thúc ở arr[i]

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    lis.assign(n, 1);
}

void LIS(){
    int crr = 1;
    while (crr < n){
        for (int i = 0; i < crr; i++){
            if (arr[i] < arr[crr]){
                lis[crr] = max(lis[crr], lis[i]+1); // vì arr[i] < arr[crr] nên là sẽ nối vào lis[i] và +1
                // lis[i]++; // nếu muốn khởi tạo như này thì phải đặt mảng lis tắt cả bằng 0 trước vì chúng ta sẽ đếm
            }
        }
        res = max(res, lis[crr]);
        crr++;
    }
    return;
}

int main() {

    input();

    LIS();

    cout << res << endl;

    return 0;
}