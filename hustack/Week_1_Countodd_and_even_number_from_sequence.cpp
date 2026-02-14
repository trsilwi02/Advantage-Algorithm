#include <bits/stdc++.h>
using namespace std;

int main(){
    int odd = 0;
    int even = 0;

    int n;
    cin >> n;
    int arr[99999];

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0){
            even ++;
        } else {
            odd++;
        }
    }

    cout << odd << " " << even << endl;

    return 0;


}