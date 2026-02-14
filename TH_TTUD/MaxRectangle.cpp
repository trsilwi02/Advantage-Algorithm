#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> adj[i][j];
        }
    }
    int ans = 0;
    vector<int> dp(m, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (adj[i][j] == 0) dp[j] = 0;
            else dp[j]++;
        }

        stack<int> st;
        for (int j = 0; j < m; j++){
            while(!st.empty() && dp[j] < dp[st.top()]){
                int top = st.top();
                st.pop();
                int height = dp[top];
                int weight = j - top;
                ans = max(ans, height*weight);
            }
        }
        while (!st.empty()){
            int top = st.top();
                st.pop();
                int height = dp[top];
                int weight = m - top;
                ans = max(ans, height*weight);
        }
    }
    
    cout << ans << endl;
    return 0;
}