#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1;
    while (n * i < 100){
        i++;
    }

    while (n*i < 999){
        cout << n*(i++) << " ";
    }
}