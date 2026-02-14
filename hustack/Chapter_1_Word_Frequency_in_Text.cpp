#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;

    map<string, int> dictionary;

    // Vòng lặp đọc từng dòng cho đến khi hết input (Ctrl+Z trên Windows hoặc Ctrl+D trên Linux/macOS)
    while (getline(cin, s)) {
        // Sử dụng stringstream để tách từng từ trong dòng
        stringstream ss(s);
        string word;
        
        // Tách chuỗi thành từng từ và đếm số lần xuất hiện của mỗi từ
        while (ss >> word) {
            dictionary[word]++;
        }
    }

    for (const auto pair : dictionary){
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}