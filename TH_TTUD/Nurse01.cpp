#include <bits/stdc++.h>
using namespace std;

int n, w1, w2, count_ans = 0;

void input(){
    cin >> n >> w1 >> w2;
}

void bruteforce(int flow, int day, int last){
    if (day >= n){
        if (flow == 0 || (flow >= w1 && flow <= w2)) {
            count_ans++;
        }
        return;
    }

    if (flow < w2){ // đi làm
        bruteforce(flow+1, day+1, 1);
    }
    if (last == 1 && ((flow >= w1 && flow <= w2) || day == 0)){ // nghỉ
        bruteforce(0, day+1, 0);
    }
}

int main(){
    input();
    bruteforce(0,0,1);
    cout << count_ans << endl;
    return 0;
}