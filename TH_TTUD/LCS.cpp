#include<bits/stdc++.h>
using namespace std;

// DAY CON CHUNG DAI NHAT

vector<vector<int>> adj;
int n, m;
vector<int> arr1, arr2;

void input(){
    cin >> n >> m;
    arr1.push_back(-1);
    arr2.push_back(-1);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr1.push_back(tmp);
    }
    for (int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        arr2.push_back(tmp);
    }
    adj.resize(n+1, vector<int> (m+1, 0)); // khởi tạo = 0
}

int build(){
    for (int i = 1; i <= n; i++) { // Duyệt qua chuỗi arr1
        for (int j = 1; j <= m; j++) { // Duyệt qua chuỗi arr2
            if (arr1[i] == arr2[j]) {
                // Nếu phần tử bằng nhau, độ dài LCS tăng thêm 1
                // bằng cách lấy giá trị đường chéo (trước đó 1 kí tự ở cả 2 chuỗi)
                adj[i][j] = adj[i-1][j-1] + 1; // <--- SỬA TẠI ĐÂY
            } else {
                // Nếu không bằng nhau, lấy giá trị lớn nhất từ ô trên (bỏ arr1[i])
                // hoặc ô bên trái (bỏ arr2[j])
                adj[i][j] = max(adj[i-1][j], adj[i][j-1]);
            }
        }
    }
    
    return adj[n][m];
}

int main(){
    input();
    cout << build() << endl;
    return 0;
} 