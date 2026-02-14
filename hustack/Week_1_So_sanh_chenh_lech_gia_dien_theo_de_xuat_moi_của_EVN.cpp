#include <bits/stdc++.h>
using namespace std;

double OldPrice(long long eletric){
    double total;
    if (eletric <= 50){
        total = eletric * 1.728;
    } else if (eletric <= 100){
        total = eletric * 1.786;
    } else if (eletric <= 200) {
        total = eletric * 2.074;
    }else if (eletric <= 300){
        total = eletric * 2.612;
        
    } else if (eletric <= 400) {
        total = eletric * 2.919;
    } else {
        total = eletric * 3.015;
    }

    return total * 1.1;
}

double NewPrice(long long electric){
    double total;
    if (electric <= 100){
        total = electric * 1.728;
    } else if (electric <= 200){
        total = electric * 2.074;
    } else if (electric <= 400){
        total = electric * 2.612;
    } else if (electric <= 700) {
        total = electric * 3.111;
    } else {
        total = electric * 3.457;
    }

    return total * 1.1;
}

int main(){
    long long input;
    cin >> input;

    double result = NewPrice(input) - OldPrice(input);

    cout << fixed << setprecision(2) << result;

    return 0;
}