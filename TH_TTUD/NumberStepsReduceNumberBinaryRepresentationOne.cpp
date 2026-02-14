#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int ToNumber(string s){
    int n = s.length();
    int tmp = 0;
    for (int i = n-1; i >= 0; i--){
        if (s[i] == '1') tmp += (int)pow(2, (n-1)-i);
    }
    return tmp;
}

void countStep(int crr){
    if (crr == 1) return;
    if (crr % 2 == 0){
        ans++;
        countStep(crr / 2);
    } else {
        ans++;
        countStep(crr+1);
    }
}

int main(){
    string s;
    cin >> s;

    int n = ToNumber(s);
    countStep(n);
    cout << ans << endl;
    return 0;
}

// public int NumSteps(string s) {
//         int ans = 0;
//         var bits = new System.Collections.Generic.List<char>(s);

//         while(bits.Count > 1){
//             int n = bits.Count-1;
//             int i = n;
//             if (bits[i] == '0'){
//                 bits.RemoveAt(n);
//                 ans++;
//             } else {
//                 while (i >= 0){
//                     if (bits[i] == '1'){
//                         bits[i] = '0';
//                         i--;
//                     }else{
//                         bits[i] = '1';
//                         break;
//                     }
//                 }

//                 if (i < 0){
//                     bits.Insert(0, '1');
//                 }

//                 ans++;
//             }
//         }
//         return ans;
//     }