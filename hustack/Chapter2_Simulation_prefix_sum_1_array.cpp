#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() { int n;
    // --- 1. Đọc số lượng phần tử N ---
    if (!(cin >> n)) return;

    // Khai báo mảng A (dữ liệu gốc) và P (Mảng Tổng Tiền Tố).
    // Dùng vector để cấp phát động, kích thước n+1 (dùng 1-based indexing).
    // Dùng 'long long' cho mảng P để đảm bảo không bị tràn số, vì tổng của 10^5 số, mỗi số 1000, có thể lên đến 10^8, 
    // tuy nhiên nếu n lớn hơn (dù đề bài giới hạn n=10^5) hoặc giá trị a_i lớn hơn, tổng có thể vượt quá giới hạn của 'int'.
    vector<int> A(n + 1);
    vector<long long> P(n + 1, 0); // Khởi tạo P[0] = 0

    // --- 2. Xây dựng Mảng Tổng Tiền Tố (Prefix Sum Array) ---
    for (int i = 1; i <= n; ++i) {
        // Đọc giá trị gốc a_i
        cin >> A[i];

        // Công thức tính tổng tiền tố: P[i] = P[i-1] + a_i
        // P[i] lưu tổng từ a_1 đến a_i
        P[i] = P[i - 1] + A[i];
    }

    int Q;
    // --- 3. Đọc số lượng truy vấn Q ---
    if (!(cin >> Q)) return;

    // --- 4. Xử lý Truy vấn ---
    for (int k = 0; k < Q; ++k) {
        int i, j;
        
        // Đọc chỉ số bắt đầu (i) và kết thúc (j) của truy vấn
        if (!(cin >> i >> j)) break;

        // Công thức tính tổng đoạn con (từ i đến j)
        // Sum(i, j) = (a_1 + ... + a_j) - (a_1 + ... + a_{i-1})
        // Sum(i, j) = P[j] - P[i-1]
        long long result = P[j] - P[i - 1];
        
        // In kết quả
        cout << result << "\n";
    }
}

int main() {
    solve();
    return 0;
}