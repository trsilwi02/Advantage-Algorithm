#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++){
        while (!st.empty() && arr[i] < arr[st.top()]){
            int top = st.top();
            st.pop();
            int height = arr[top];
            int weight = i - top;
            ans = max(ans, height * weight);
        }
        st.push(i);
    }

    while(!st.empty()){
        int top = st.top();
            st.pop();
            int height = arr[top];
            int weight = n - top;
            ans = max(ans, height * weight);
    }

    cout << ans << endl;
    return 0;
}