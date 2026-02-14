#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000000;
int n, x[maxN], visited[maxN];

void Try(int k){ // thử cho vị trí thứ k
    for (int v = 1; v <= n; v++){
        if (visited[v] == 0){
            visited[v] = 1;
            x[k] = v;

            if (k >= n){
                for (int i = 1; i <= n; i++){
                    cout << x[i] << " ";
                }
                cout << endl;
            } else {
                Try(k+1);
            }

            visited[v] = 0;

        }
    }
}

int main(){
    cin >> n;
    Try(1);

    return 0;
}