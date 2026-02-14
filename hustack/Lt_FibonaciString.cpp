#include <bits/stdc++.h>
using namespace std;

int a, b;
long long F[100];

char solve(string s1, string s2, int k){
    F[1] = s1.length();
    F[2] = s2.length();

    // tạo arr độ dài
    int n = 2; // bất đầu từ 2
    while (F[n] <= k){
        n++;
        // F[n] sẽ vượt long long, nhưng k < 10^18 nên n hiện tại hoặc n-1 đã đủ bao phủ k
        if (F[n-1] > 4e18) break; 
        F[n] = F[n-1] + F[n-2];
    }

    while (n>2){
        if (k < F[n-1]){ 
            n = n-1;
        } else {
            k -= F[n-1];
            n = n-2;
        }
    }

    if (n==1) return s1[k]; // n chi có thể = 1 hoặc 2
    else return s2[k];
} 

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    a = s1.length();
    b = s2.length();

    int k;
    cin >> k;

    cout << solve(s1, s2, k);

}