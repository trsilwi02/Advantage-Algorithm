#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        // Lúc này phương trình trở thành bx + c = 0
        if (b == 0) {
            cout << "NO SOLUTION";
        } else {
            double x = -c / b;
            cout << fixed << setprecision(2) << x;
        }
        return 0;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "NO SOLUTION";
    } else if (delta == 0) {
        double x0 = -b / (2 * a);
        cout << fixed << setprecision(2) << x0;
    } else {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        if (x1 > x2) swap(x1, x2);
        cout << fixed << setprecision(2) << x1 << " " << x2;
    }

    return 0;
}
