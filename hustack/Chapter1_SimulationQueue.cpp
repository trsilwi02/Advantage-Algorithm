#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    string cmd;

    while (true) {
        getline(cin, cmd);
        if (cmd == "#") break;

        if (cmd.rfind("PUSH", 0) == 0) { // bắt đầu bằng "PUSH"
            int v = stoi(cmd.substr(5)); // lấy số sau "PUSH "
            q.push(v);
        } 
        else if (cmd == "POP") {
            if (q.empty()) {
                cout << "NULL\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}