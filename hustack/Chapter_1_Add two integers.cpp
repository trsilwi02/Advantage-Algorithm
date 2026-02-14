#include <bits/stdc++.h>
using namespace std;

// Hàm in số kiểu __int128
void printInt128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string s;
    while (x > 0) {
        int digit = x % 10;
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    __int128 a, b;
    string sa, sb;
    cin >> sa >> sb;

    // chuyển string sang __int128
    a = 0;
    for (char c : sa) a = a * 10 + (c - '0');
    b = 0;
    for (char c : sb) b = b * 10 + (c - '0');

    __int128 sum = a + b;

    printInt128(sum);
    return 0;
}
