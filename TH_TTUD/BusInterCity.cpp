#include <bits/stdc++.h>
using namespace std;

struct State{
    int cost, city, bus, crrindex;
    bool operator > (const State& other) const{
        return cost > other.cost;
    };
};

int n , m;
vector<pair<int, int>> costes;
vector<vector<int>> adj;

vector<int> d; //số tiền ít nhất để đi đến thành phố i


void input(){
    cin >> n >> m;
    costes.resize(n+1);
    adj.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> costes[i].first >> costes[i].second;
    }

    for (int i = 1; i <= m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
    }
    d.assign(n+1, INT_MAX);
}

void Dijkstra(int start){
    priority_queue<State, vector<State>, greater<State>> pq;
    d[start] = 0;
    pq.push({0, start, 0, 0}); //cost = 0, đang ở thành phố start, đang trên bus số 0, còn đi dược 0 city nữa
    while (!pq.empty()){
        State crrState = pq.top();
        pq.pop();
        int crrCity = crrState.city;
        int d_city = crrState.cost;
        int crrBus = crrState.bus;
        int nxIndex = crrState.crrindex;

        if (d_city > d[crrCity]) continue; //nếu đang bé hơn cái bé nhất thì như muối bỏ biển
        d[crrCity] = d_city;
        for (int toCity : adj[crrCity]){
            if (nxIndex != 0){
                if (d[toCity] > d[crrCity]){
                    d[toCity] = d[crrCity];
                    pq.push({d[toCity], toCity, crrBus, nxIndex-1});
                }
                
            } else { //đã đi hết bus
                if (d[toCity] >= d[crrCity] + costes[crrCity].first){
                    d[toCity] = d[crrCity] + costes[crrCity].first; //đi xe bus đếm toCity
                    pq.push({d[toCity], toCity, crrCity, costes[crrCity].second});
                }
            }
        }
    }
}

int main(){
    input();
    Dijkstra(1);
    cout << d[n] << endl;
    return 0;
}