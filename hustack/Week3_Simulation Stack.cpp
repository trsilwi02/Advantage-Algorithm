    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        stack<int> st;

        while (true) {
            string s;
            cin >> s;
            if (s == "#") break;
            else if (s == "PUSH"){
                int v;
                cin >> v;
                st.push(v);
            } else if (s == "POP"){
                if (st.empty()) cout << "NULL\n";
                else {
                    cout << st.top() << endl;
                    st.pop();
                }
            }
        }

        return 0;
    }