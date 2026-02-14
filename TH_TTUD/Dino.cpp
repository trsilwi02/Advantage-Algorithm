#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    stack<int> st;
    queue<int> qu;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = n-1; i >=0; i--){
        st.push(arr[i]);
    }

    string s;
    cin >> s;
    vector<char> cmd(s.begin(), s.end());
    for (char c : cmd){
        if (c == 'C'){
            if(!st.empty()){
                qu.push(st.top());
                st.pop();
            }
        } else {
            if(!qu.empty()){
                st.push(qu.front());
                qu.pop();
            }
        }
    }

    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}