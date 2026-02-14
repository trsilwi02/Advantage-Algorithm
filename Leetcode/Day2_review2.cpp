#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while (t > 0){
        int n;
    cin >> n;
    vector<int> arr;

    arr.resize(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> f(n, 0);
    int ans = 0;
    f[arr[0]] = 1;
    
    for (int i = 1; i < n; i++){
        int x = arr[i];
        if (f[x-1] == 0){
            f[x] = 1;
        } else {
            f[x] = max(f[x-1]+1, f[x]);
            ans = max(ans, f[x]);
        }
    }
    cout << ans << endl;
        t--;
    }

    return 0;
}