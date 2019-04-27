#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string as, bs; cin >> as >> bs;
        double a, b; a = stod(as); b = stod(bs);
        complex<double> c(a, b);
        complex<double> d(0, 0);
        for (int i = 0; i < 55; i++) {
            if (abs(d) > 100 || i == 53) {
                cout << as;
                if (bs[0] != '-') cout << "+";
                cout << bs << "i ";
                if (i <= 10) cout << "RED";
                else if (i <= 20) cout << "ORANGE";
                else if (i <= 30) cout << "YELLOW";
                else if (i <= 40) cout << "GREEN";
                else if (i <= 50) cout << "BLUE";
                else cout << "BLACK";
                cout << endl;
                break;
            }
            d = d * d;
            d += c;
        }
    }
    return 0;
}
