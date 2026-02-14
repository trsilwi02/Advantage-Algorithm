#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm giải quyết bài toán bằng Two Pointers (O(N log N) thời gian)
void solve_two_pointers() {
    long long n;
    int m;
    
    if (!(cin >> n >> m)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // BƯỚC 1: Sắp xếp mảng (Cần thiết cho Two Pointers)
    // Độ phức tạp O(N log N)
    sort(arr.begin(), arr.end()); 

    int count = 0;
    long long left = 0;
    long long right = n - 1;

    // BƯỚC 2: Dùng Two Pointers (O(N) thời gian)
    // Điều kiện left < right đảm bảo i < j và không đếm cùng một phần tử 2 lần.
    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == m) {
            // Tìm thấy một cặp
            count++;
            left++;  // Di chuyển cả hai con trỏ để tìm cặp mới
            right--; 
        } else if (current_sum < m) {
            // Tổng quá nhỏ, cần tăng giá trị nhỏ hơn (tăng left)
            left++;
        } else { // current_sum > m
            // Tổng quá lớn, cần giảm giá trị lớn hơn (giảm right)
            right--;
        }
    }

    cout << count << endl;
}

int main(){
    solve_two_pointers();
    return 0;
}