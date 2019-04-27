#include <iostream>
#include <cmath>

using namespace std;

int cross(int x1, int y1, int x2, int y2, int x3, int y3) {
    int xa = x2 - x1, ya = y2 - y1;
    int xb = x2 - x3, yb = y2 - y3;
    int crv = xa * yb - xb * ya;
    if (crv == 0) return 0;
    else return crv / abs(crv);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int q; cin >> q;
        bool ans = 0;
        while (q--) {
            int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
            bool good = (cross(x3, y3, x1, y1, x2, y2) != cross(x4, y4, x1, y1, x2, y2)) && (cross(x1, y1, x3, y3, x4, y4) != cross(x2, y2, x3, y3, x4, y4));
            if (good) ans = 1;
        }
        cout << (!ans ? "YES" : "NO") << endl;
    }
    return 0;
}
