#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;

int n, m, k, ans = INT_MAX, soMon[maxn];
bool conflict[maxn][maxn] , adj[maxn][maxn];

int assigned[maxn];

void input(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++){
            int tmp1;
            cin >> tmp1;
            adj[i][tmp1] = true; // giáo viên i dạy đc môn tmp1
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        conflict[tmp1][tmp2] = true; // gán conflict cho các điểm = 1 là có conflict
        conflict[tmp2][tmp1] = true; // 2 chiều
    }
}

bool check(int k, int v){ // có xếp đc môn k vào cho giáo viên v hay không
    if (adj[v][k] == false) return false; // giáo viên v không dạy đc môn k
    if (assigned[k] != 0) return false; // môn này đã đc phân cho giáo viên khác
    for (int i = 1; i <= m; i++){
        if (conflict[k][i] == true && assigned[i] == v) { // nếu có conflict của môn i và k nếu gv v dạy cả 2 môn i và k
            return false;
        }
    }

    return true;
}

void Try(int k) {// thử tìm giáo viên cho môn k
    for (int v = 1; v <= n; v++){
        if (check(k, v)){ // kiểm tra cho môn k và gv i có ok không
            assigned[k] = v; // môn k sẽ do gv i phụ trách
            soMon[v]++;
            
            int load = 0;
            if (k == m){ // đã đến môn cuối
                for (int i = 1; i <= n; i++){
                    load = max(load, soMon[i]);
                }

                ans = min(load, ans); // tìm so mon be nhât
            }

            if (soMon[v] < ans){
                Try(k+1);
            }
            soMon[v]--;
            assigned[k] = 0;
        }
    }
}

int main(){
    input();
    Try(1);

    cout << ans << endl;
    return 0;
}