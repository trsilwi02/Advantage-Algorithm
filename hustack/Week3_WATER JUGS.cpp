#include <bits/stdc++.h>
using namespace std;

struct State{
    int x, y, step;
};

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if (c > max(a, b) || c % gcd(a, b) != 0){
        cout << -1;
        return 0;
    }

    bool visited[901][901];
    queue<State> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()){
        State cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int step = cur.step;

        if (x == c || y == c){
            cout << step;
            return 0;
        }

        vector<pair<int, int>> nextState;
        nextState.push_back({a, y});
        nextState.push_back({x, b});
        nextState.push_back({0, y});
        nextState.push_back({x, 0});

        int pour = min (x, b-y);
        nextState.push_back({x-pour, y+pour});

        pour = min(y, a-x);
        nextState.push_back({x+pour, y-pour});

        for (auto[nx, ny] : nextState){
            if (!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny, step+1});
            }
        }
    }

    cout << -1;
    return 0;
}