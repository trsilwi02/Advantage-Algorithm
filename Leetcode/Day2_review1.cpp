#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t > 0){
        int ans = 0;

        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        
        int m;
        cin >> m;
        set<int> s1;
        for (int i = 0; i < m; i++){
            int tmp;
            cin >> tmp;
            if(s.count(tmp) != 0 && s1.count(tmp) == 0) {
                s1.insert(tmp); 
                ans++;
            }
        }

        cout << ans << endl;

        t--;
    }
    return 0;
}