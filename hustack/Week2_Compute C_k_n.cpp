#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000;

long long fact[MAXN+1];
long long invFact[MAXN+1];

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void initFactorial() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    invFact[MAXN] = power(fact[MAXN], MOD-2);
    for (int i = MAXN-1; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

long long C(int k, int n) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
}

int main() {
    int k, n;
    cin >> k >> n;

    initFactorial();
    cout << C(k, n) << endl;

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// long long C (int a, int b){
//     if (a > b) return 0;
//     else if (a == 0 || a == b) return 1;
//     else {
//         return C(a-1, b-1) + C(a, b-1);
//     }
// }

// int main(){
//     int a, b;
//     cin >> a >> b;

//     int result = C(a, b);

//     cout << result;
// }
