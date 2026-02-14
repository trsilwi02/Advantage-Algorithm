#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<int> m;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (m.find(tmp) != m.end()){
            cout << 1 <<"\n";
        } else {
            cout << 0 << "\n";
            m.insert(tmp);
        }
    }

    return 0;
}