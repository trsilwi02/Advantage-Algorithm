#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

bool check(double mid){
    vector<double> pref(n+1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + arr[i] - mid;

    double min_pref = 0; // pref[0]
    for (int i = m; i <= n; i++) {
        min_pref = min(min_pref, pref[i-m]);
        if (pref[i] - min_pref >= 0)
            return true;
    }
    return false;
}



int main(){
    cin >> n >> m;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    double l = *min_element(arr.begin(), arr.end());
    double r = *max_element(arr.begin(), arr.end());

    int count_caculate = 50;
    while (count_caculate != 0){
        double mid = (l + r)/2;
        if (check(mid)){
            l = mid;
        } else {
            r = mid;
        }
        count_caculate--;
    }

    cout << fixed << setprecision(5) << l << endl;
    return 0;
}