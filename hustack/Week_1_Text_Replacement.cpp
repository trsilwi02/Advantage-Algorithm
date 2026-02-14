#include <iostream>
#include <string>
using namespace std;

string replaceString(string text, string p1, string p2) {
    string result = text;
    size_t pos = 0;
    
    // Tìm và thay thế tất cả các xuất hiện của p1 bằng p2
    while ((pos = result.find(p1, pos)) != string::npos) {
        result.replace(pos, p1.length(), p2);
        pos += p2.length(); // Di chuyển vị trí tìm kiếm để tránh lặp vô hạn
    }
    
    return result;
}

int main() {
    string p1, p2, text;
    
    getline(cin, p1);
    
    getline(cin, p2);
    
    getline(cin, text);
    
    // Thực hiện thay thế
    string result = replaceString(text, p1, p2);
    
    cout << result << endl;
    
    return 0;
}

/* 
Test với ví dụ trong đề bài:
Input:
AI
Artificial Intelligence
Recently, AI is a key technology. AI enable efficient operations in many fields.

Output:
Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.
*/