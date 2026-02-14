#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    string line;
    // Đọc dấu *
    while (getline(cin, line)) {
        if (line == "*") break;
    }

    // Xử lý các truy vấn
    while (getline(cin, line)) {
        if (line == "***") break;

        if (line == "find-max") {
            cout << *max_element(a.begin(), a.end()) << endl;
        } else if (line == "find-min") {
            cout << *min_element(a.begin(), a.end()) << endl;
        } else if (line == "sum") {
            int total = 0;
            for (int x : a) total += x;
            cout << total << endl;
        } else if (line.find("find-max-segment") == 0) {
            stringstream ss(line);
            string cmd;
            int i, j;
            ss >> cmd >> i >> j;
            int max_val = a[i - 1];
            for (int k = i - 1; k < j; ++k) {
                max_val = max(max_val, a[k]);
            }
            cout << max_val << endl;
        }
    }

    return 0;
}
