#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long m;
    cin >> n;
    cin >> m;
    while (n--) {
        string s;
        cin >> s;

        long long hashValue = 0;
        for (char c : s) {
            hashValue = (hashValue * 256 + (int)c) % m;
        }

        cout << hashValue << "\n";
    }

    return 0;
}