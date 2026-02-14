// 

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 30; // N tối đa khoảng 11-12, khai báo dư chút
int n, k;
int c[MAXN][MAXN];   // Ma trận kề (chi phí)
int x[MAXN];         // Lưu lộ trình để debug nếu cần (không bắt buộc)
bool visited[MAXN];  // Đánh dấu đã thăm
int load = 0;        // Số khách đang trên xe
int f = 0;           // Chi phí hiện tại
int f_best = INT_MAX;// Chi phí tốt nhất (kết quả)
int cmin = INT_MAX;  // Cạnh nhỏ nhất trong đồ thị

// Hàm kiểm tra xem có thể đi đến điểm v hay không
bool check(int v) {
    if (visited[v]) return false; // Đã đi rồi thì thôi

    if (v <= n) { 
        // Nếu v là điểm đón (1..n)
        if (load < k) return true; // Xe còn chỗ thì đón được
        else return false;
    } else { 
        // Nếu v là điểm trả (n+1..2n)
        if (visited[v - n]) return true; // Phải đón khách (v-n) rồi mới được trả
        else return false;
    }
}

// Hàm quay lui
// k_th: đây là điểm thứ mấy trong hành trình (1 -> 2*n)
// prev: điểm vừa đi qua trước đó
void Try(int k_th, int prev) {
    // CÔNG THỨC NHÁNH CẬN:
    // Nếu chi phí hiện tại + (số bước còn lại * cạnh nhỏ nhất) >= kỷ lục hiện tại
    // thì cắt nhánh, không đi tiếp nữa.
    // Số bước còn lại = (2*n - (k_th - 1)) + 1 bước về đích = 2*n - k_th + 2
    // Tuy nhiên logic đơn giản: còn (2*n+1) - k_th bước nữa (tính cả về 0)
    if (f + (2 * n + 1 - k_th) * cmin >= f_best) return;

    for (int v = 1; v <= 2 * n; v++) {
        if (check(v)) {
            // 1. Cập nhật trạng thái
            x[k_th] = v;          // Lưu vết (nếu cần)
            visited[v] = true;
            f += c[prev][v];      // Cộng chi phí
            
            if (v <= n) load++;   // Nếu là điểm đón: tăng tải
            else load--;          // Nếu là điểm trả: giảm tải

            // 2. Kiểm tra đích hoặc gọi đệ quy
            if (k_th == 2 * n) {
                // Đã đi hết các điểm, giờ cộng chi phí về 0
                int total_cost = f + c[v][0];
                if (total_cost < f_best) {
                    f_best = total_cost;
                }
            } else {
                Try(k_th + 1, v);
            }

            // 3. Trả lại trạng thái (Backtrack)
            if (v <= n) load--;   // Trả lại tải
            else load++;
            
            visited[v] = false;   // Bỏ đánh dấu
            f -= c[prev][v];      // Trừ chi phí
        }
    }
}

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    
    // Nhập ma trận và tìm cmin
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin) {
                cmin = c[i][j];
            }
        }
    }

    // Khởi tạo
    visited[0] = true; // Điểm 0 coi như đã thăm (hoặc không quan trọng vì loop từ 1)
    
    // Bắt đầu thuật toán từ bước thứ 1, điểm xuất phát là 0
    Try(1, 0);

    cout << f_best << endl;

    return 0;
}