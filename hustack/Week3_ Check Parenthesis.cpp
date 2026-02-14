#include <bits/stdc++.h>
using namespace std;

int Check(string cmd){
    stack<char> st;
    for (char c : cmd){
        if (c == '(' || c == '[' || c == '{'){
            st.push(c);
        } else {
            if (st.empty()) return 0;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')){
                    return 0;
                }
            st.pop();
        }
    }
    if (st.empty()) return 1;
    else return 0;
}

int main(){
    string cmd;
    cin >> cmd;
    int ans;
    ans = Check(cmd);
    cout << ans;
    return 0;
}