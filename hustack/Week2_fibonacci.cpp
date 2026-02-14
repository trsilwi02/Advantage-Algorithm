// #include <bits/stdc++.h>
// using namespace std;

// long long Fibonacci(int n){
//     if (n == 0) return 0;
//     else if (n == 1) return 1;

//     else {
//         return Fibonacci(n-1) + Fibonacci(n-2);
//     }
// }

// int main(){
//     int n;
//     cin >> n;

//     long long ans = Fibonacci(n-1);

//     cout << ans;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> f(n+2, 0);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    cout << f[n-1] << "\n";
    return 0;
}
