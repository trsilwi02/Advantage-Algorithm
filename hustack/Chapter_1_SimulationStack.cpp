#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    string cmd;

    while (true) {
        getline(cin, cmd);
        if (cmd == "#") break;

        if (cmd.rfind("PUSH", 0) == 0) { // bắt đầu bằng "PUSH"
            int v = stoi(cmd.substr(5)); // lấy số sau "PUSH "
            s.push(v);
        } 
        else if (cmd == "POP") {
            if (s.empty()) {
                cout << "NULL\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }

    return 0;
}