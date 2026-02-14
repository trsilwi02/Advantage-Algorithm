#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Khai báo hằng số cho kích thước đồ thị
// N <= 10^4, nên dùng mảng/vector kích thước 10005 để đánh chỉ mục từ 1
const int MAXN = 10005;

// Ma trận dung lượng (Capacity Matrix)
// capacity[u][v] lưu trữ dung lượng thặng dư từ u đến v.
// Lưu ý: Mặc dù N lên đến 10^4, M lên đến 10^6, việc dùng ma trận kề
// là T(N^2) sẽ không hiệu quả. Ta nên dùng danh sách kề để tiết kiệm bộ nhớ.
// Tuy nhiên, để đơn giản hóa cài đặt Edmonds-Karp, ta sẽ dùng ma trận kề cho ví dụ này,
// nhưng cần lưu ý về hiệu suất với N lớn. 
// Nếu N lớn (như 10^4) và M lớn (10^6), bạn NÊN dùng Danh sách kề để biểu diễn đồ thị.

// Trong trường hợp này, vì N=10^4, việc cấp phát vector<vector<int>> (10005 x 10005) 
// sẽ gặp vấn đề về bộ nhớ (khoảng 400MB) và tốc độ.
// Ta sẽ dùng **Danh sách kề** kết hợp với **Map** hoặc **Vector** để mô phỏng ma trận
// chỉ cho các đỉnh kề nhau, mặc dù Edmonds-Karp thường được dạy với ma trận.
// Để tương thích tốt hơn với ràng buộc N=10^4, ta sẽ dùng **danh sách kề (Adjacency List)**.

// Cấu trúc để lưu trữ cạnh/cung
struct Edge {
    int to;    // Đỉnh đích
    int cap;   // Dung lượng/Dung lượng thặng dư
    int rev;   // Chỉ số của cung nghịch (reverse edge) trong danh sách kề của đỉnh 'to'
};

// Danh sách kề: adj[u] là vector các cung đi ra từ u
vector<Edge> adj[MAXN];

// Hàm thêm cung và cung nghịch vào đồ thị
void add_edge(int u, int v, int c) {
    // Cung thuận (u -> v)
    Edge forward_edge = {v, c, (int)adj[v].size()};
    adj[u].push_back(forward_edge);

    // Cung nghịch (v -> u) ban đầu có dung lượng thặng dư = 0
    // Cung này được thêm để đại diện cho việc "hoàn tác" luồng.
    Edge backward_edge = {u, 0, (int)adj[u].size() - 1}; 
    adj[v].push_back(backward_edge);
}

// Mảng parent và index_on_parent_list được sử dụng để truy vết đường đi
// parent[v]: Đỉnh trước v trên đường đi tăng luồng
// index_on_parent_list[v]: Chỉ số của cung (parent[v], v) trong adj[parent[v]]
int parent[MAXN];
int index_on_parent_list[MAXN];

// BFS để tìm đường đi tăng luồng
int bfs(int s, int t, int N) {
    // Khởi tạo các mảng
    fill(parent, parent + N + 1, -1);
    fill(index_on_parent_list, index_on_parent_list + N + 1, -1);

    // flow_on_path[v]: Lượng luồng tối đa có thể truyền đến v
    vector<int> flow_on_path(N + 1, 0);

    queue<int> q;
    q.push(s);
    flow_on_path[s] = INT_MAX; // Nút nguồn có lượng luồng ban đầu là vô hạn

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) {
            // Đã tìm thấy đường đi đến t
            break;
        }

        // Duyệt qua các cung đi ra từ u
        for (int i = 0; i < adj[u].size(); ++i) {
            Edge& e = adj[u][i];
            int v = e.to;
            int cap = e.cap;

            // Nếu đỉnh v chưa được thăm (parent[v] == -1) và còn dung lượng thặng dư
            if (parent[v] == -1 && cap > 0) {
                parent[v] = u;
                index_on_parent_list[v] = i;
                
                // Cập nhật lượng luồng tối đa có thể truyền đến v
                flow_on_path[v] = min(flow_on_path[u], cap);

                q.push(v);
            }
        }
    }

    // Trả về lượng luồng có thể tăng thêm
    return flow_on_path[t] > 0 ? flow_on_path[t] : 0;
}

// Hàm chính tính luồng cực đại
long long max_flow_edmonds_karp(int s, int t, int N) {
    long long total_flow = 0;
    int path_flow;

    // Vòng lặp chính: lặp cho đến khi không tìm thấy đường đi tăng luồng nào nữa
    while ((path_flow = bfs(s, t, N)) > 0) {
        // Cộng dồn luồng tăng thêm
        total_flow += path_flow;

        // Cập nhật đồ thị thặng dư bằng cách đi ngược từ t về s
        int curr = t;
        while (curr != s) {
            int prev = parent[curr];
            int index = index_on_parent_list[curr];

            // Cung thuận (prev -> curr)
            // Giảm dung lượng thặng dư của cung thuận
            adj[prev][index].cap -= path_flow;

            // Cung nghịch (curr -> prev)
            // Tăng dung lượng thặng dư của cung nghịch (index của cung nghịch là adj[prev][index].rev)
            adj[curr][adj[prev][index].rev].cap += path_flow;

            curr = prev;
        }
    }

    return total_flow;
}

// Hàm đọc input và gọi giải thuật
int main() {
    // Tăng tốc độ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // Đọc N (số đỉnh) và M (số cung)
    if (!(cin >> N >> M)) return 0;

    int s, t;
    // Đọc s (nguồn) và t (đích)
    if (!(cin >> s >> t)) return 0;

    // Đọc M cung
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        if (!(cin >> u >> v >> c)) break;
        add_edge(u, v, c);
    }

    // Tính và in ra luồng cực đại
    long long result = max_flow_edmonds_karp(s, t, N);
    cout << result << endl;

    return 0;
}