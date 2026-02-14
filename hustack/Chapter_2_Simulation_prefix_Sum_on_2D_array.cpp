#include <iostream>
#include <vector>

using namespace std;

// Hằng số định nghĩa kích thước tối đa của bảng
const int MAXN = 1005; 
const int MAXM = 1005;

// Khai báo mảng 2D cho dữ liệu gốc (A) và mảng tổng tiền tố (P)
// Dùng long long cho mảng tổng tiền tố để tránh tràn số, vì tổng có thể lớn.
int A[MAXN][MAXM];
long long P[MAXN][MAXM];

long long query_sum(int r1, int c1, int r2, int c2) {
    // Tổng của hình chữ nhật từ (1,1) đến (r2, c2)
    long long total = P[r2][c2];

    // Trừ đi vùng bị loại bỏ phía trên (từ hàng r1-1 trở lên)
    long long excluded_top = P[r1 - 1][c2];

    // Trừ đi vùng bị loại bỏ bên trái (từ cột c1-1 trở lên)
    long long excluded_left = P[r2][c1 - 1];

    // Cộng bù lại phần đã bị trừ hai lần (vùng trên-trái: (1,1) đến (r1-1, c1-1))
    long long compensation = P[r1 - 1][c1 - 1];

    return total - excluded_top - excluded_left + compensation;
}

int main() {
    int n, m;

    // --- 1. Đọc kích thước bảng ---
    if (!(cin >> n >> m)) return 0; // Đảm bảo đọc thành công

    // --- 2. Xây dựng Mảng tổng tiền tố (2D Prefix Sum Array) ---
    
    // Đọc dữ liệu gốc và tính toán mảng P
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Đọc giá trị gốc
            cin >> A[i][j];

            // Công thức tính tổng tiền tố 2D:
            // P[i][j] = Tổng các phần tử từ (1,1) đến (i,j)
            // P[i][j] = A[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
            P[i][j] = A[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    // --- 3. Xử lý Truy vấn ---
    
    int Q;
    // Đọc số lượng truy vấn
    if (!(cin >> Q)) return 0;

    for (int q = 0; q < Q; ++q) {
        int r1, c1, r2, c2;
        
        // Đọc toạ độ truy vấn
        if (!(cin >> r1 >> c1 >> r2 >> c2)) break;

        // Tính toán kết quả và in ra
        long long result = query_sum(r1, c1, r2, c2);
        cout << result << "\n";
    }

    return 0;
}