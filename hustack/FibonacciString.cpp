#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string Fibonacci(int k){
    if (k == 0) return s1;
    if (k == 1) return s2;
    return s1+s2;
}

int main(){
    cin >> s1 >> s2;

    int n;

    cin >> n;

    cout << Fibonacci(n);
    return 0;

}