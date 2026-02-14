#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    string s;
    cin >> s;

    // Kiểm tra độ dài phải đúng 10
    if (s.size() != 10 || s[4] != '-' || s[7] != '-') {
        cout << "INCORRECT\n";
        return 0;
    }

    string year = s.substr(0, 4);
    string month = s.substr(5, 2);
    string day = s.substr(8, 2);

    // Kiểm tra số
    if (!isNumber(year) || !isNumber(month) || !isNumber(day)) {
        cout << "INCORRECT\n";
        return 0;
    }

    int y = stoi(year);
    int m = stoi(month);
    int d = stoi(day);

    // Kiểm tra range tháng, ngày
    if (m < 1 || m > 12 || d < 1 || d > 31) {
        cout << "INCORRECT\n";
        return 0;
    }

    cout << y << " " << m << " " << d << "\n";
    return 0;
}
