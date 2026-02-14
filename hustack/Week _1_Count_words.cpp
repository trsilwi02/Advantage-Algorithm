#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, line;
    stringstream buffer;
    while (getline(cin, line)) {
        buffer << line << " "; // thêm dấu cách để nối dòng
    }
    text = buffer.str();

    // Tách từ bằng stringstream
    string word;
    stringstream ss(text);
    int count = 0;
    while (ss >> word) {
        count++;
    }

    cout << count;
    return 0;
}
