#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------
// 1. Cấu trúc dữ liệu cho cạnh và DSU
// ----------------------------------------------------

// Cấu trúc để lưu thông tin về một cạnh
struct Edge {
    int u, v;     // Hai đỉnh của cạnh
    int weight;   // Trọng số của cạnh
};

// Hàm so sánh dùng để sắp xếp các cạnh theo trọng số TĂNG DẦN
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Global DSU arrays
// Mảng lưu trữ đỉnh cha của mỗi thành phần liên thông
vector<int> parent;
// Mảng lưu kích thước (size) của mỗi cây DSU (dùng để tối ưu Union by Size)
vector<int> sz;

// ----------------------------------------------------
// 2. Các thao tác của Union-Find (DSU)
// ----------------------------------------------------

// Thao tác Find (Tìm gốc đại diện)
// Sử dụng Path Compression (Nén đường đi) để tối ưu
int Find(int i) {
    // Nếu i là gốc của chính nó (parent[i] == i)
    if (parent[i] == i)
        return i;
    // Đệ quy tìm gốc, đồng thời gán parent[i] về thẳng gốc
    return parent[i] = Find(parent[i]);
}

// Thao tác Union (Hợp nhất hai tập hợp)
// Sử dụng Union by Size (Hợp nhất theo Kích thước) để tối ưu
void Union(int u, int v) {
    int root_u = Find(u); // Tìm gốc của u
    int root_v = Find(v); // Tìm gốc của v

    // Nếu hai gốc khác nhau, nghĩa là chúng thuộc hai tập hợp riêng biệt
    if (root_u != root_v) {
        // Luôn gắn cây nhỏ hơn vào cây lớn hơn (dựa vào kích thước)
        if (sz[root_u] < sz[root_v])
            swap(root_u, root_v); // Đảm bảo root_u luôn là cây lớn hơn hoặc bằng
        
        parent[root_v] = root_u; // Gắn gốc nhỏ hơn (root_v) vào gốc lớn hơn (root_u)
        sz[root_u] += sz[root_v]; // Tăng kích thước của cây mới
    }
}

// Hàm Khởi tạo DSU
void init_dsu(int N) {
    parent.resize(N + 1); // Resize mảng parent cho N+1 đỉnh (từ 1 đến N)
    sz.assign(N + 1, 1);   // Khởi tạo kích thước mỗi cây ban đầu là 1
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;    // Ban đầu, mỗi đỉnh là gốc của chính nó
    }
}

// ----------------------------------------------------
// 3. Hàm giải quyết bài toán (Thuật toán Kruskal)
// ----------------------------------------------------

void solve() {
    int N, M;

    // Đọc N (số đỉnh) và M (số cạnh)
    if (!(cin >> N >> M)) return;

    // Vector để lưu trữ M cạnh
    vector<Edge> edges(M);

    // Đọc M dòng tiếp theo, mỗi dòng là một cạnh (u, v, w)
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // BƯỚC 1: Sắp xếp các cạnh
    // Sắp xếp tất cả các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compareEdges);

    // BƯỚC 2: Khởi tạo DSU
    init_dsu(N);

    // BƯỚC 3: Tiến hành thuật toán Kruskal
    long long mst_weight = 0; // Biến lưu tổng trọng số MST (dùng long long vì tổng có thể lớn)
    int edges_count = 0;      // Đếm số cạnh đã chọn cho MST (cần N-1 cạnh)

    // Duyệt qua các cạnh đã sắp xếp từ cạnh nhỏ nhất
    for (const auto& edge : edges) {
        // Nếu đã chọn đủ N-1 cạnh thì dừng
        if (edges_count == N - 1)
            break;

        // KIỂM TRA CHU TRÌNH: Nếu Find(u) != Find(v) thì KHÔNG tạo chu trình
        if (Find(edge.u) != Find(edge.v)) {
            
            // CHỌN CẠNH: Hợp nhất hai thành phần
            Union(edge.u, edge.v);
            
            // CẬP NHẬT KẾT QUẢ
            mst_weight += edge.weight;
            edges_count++;
        }
    }

    // Output kết quả
    cout << mst_weight << endl;
}

// ----------------------------------------------------
// 4. Hàm Main
// ----------------------------------------------------

int main() {
    solve(); // Gọi hàm giải quyết bài toán

    return 0;
}