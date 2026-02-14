#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    while (true){
        string cmd;
        cin >> cmd;
        if (cmd == "#") break;
        if (cmd == "PUSH"){
            int k;
            cin >> k;
            q.push(k);
        }

        else if (cmd == "POP"){
            if (!q.empty()){
                int tmp = q.front();
                q.pop();
                cout << tmp << endl;
            } else {
                cout << "NULL" << endl;
            }
            
        }
    }

    return 0;
}