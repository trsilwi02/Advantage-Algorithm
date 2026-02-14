#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = 100000007;

unsigned long long powTay(unsigned long long a, unsigned long long b){
    unsigned long long tmp = 1;
    while (b > 0){
        a %= MOD;
        if (b % 2 == 1){
            tmp = (tmp * a) % MOD;
        }
        a = (a*a) % MOD;
        b >>= 1;
    }
    return tmp;
}

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    cout << powTay(a, b) << endl;

    return 0;
}