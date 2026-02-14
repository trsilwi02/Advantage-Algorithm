#include <bits/stdc++.h>
using namespace std;

vector<int> st;

void Backtrack(int i, int n) {
    if (i == n) {
        // in ra chuỗi
        for (int x : st) cout << x;
        cout << endl;
        return;
    }

    // Nếu trước đó không phải 1 → có thể thử 0 và 1
    if (st.empty() || st.back() != 1) {
        st.push_back(0);
        Backtrack(i + 1, n);
        st.pop_back();

        st.push_back(1);
        Backtrack(i + 1, n);
        st.pop_back();
    }
    else {
        // Nếu cuối là 1 thì chỉ được đặt 0
        st.push_back(0);
        Backtrack(i + 1, n);
        st.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    Backtrack(0, n);

    return 0;
}
\