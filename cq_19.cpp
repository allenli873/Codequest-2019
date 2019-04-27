#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int val[n][4];
        for (int i = 0; i < n; i++) {
            char c; 
            cin >> val[i][0] >> c >> val[i][1] >> c >> val[i][2] >> c >> val[i][3];
        }
        bool done = 0;
        for (int i = 0; i < 32; i++) {
            bool good = 1;
            int ci = i / 8, cj = i % 8;
            cj = 7 - cj;
            bool cur = (val[0][ci] & (1 << cj)) ? 1 : 0;
            for (int j = 1; j < n; j++) {
                bool b = (val[j][ci] & (1 << cj)) ? 1 : 0;
                if (cur != b) {
                    good = 0;
                    break;
                }
            }
            if (!good) {
                int ans[4];
                for (int j = 0; j < ci; j++) ans[j] = val[0][j];
                ans[ci] = 0;
                int tmp  = 0;
                for (int j = cj + 1; j < 8; j++) tmp += (1 << j);
                ans[ci] = val[0][ci] & tmp;
                for (int j = ci + 1; j < 4; j++) ans[j] = 0;
                cout << ans[0];
                for (int i = 1; i < 4; i++) cout << "." << ans[i];
                cout << "/" << i << endl;
                done = 1;
                break;
            }
        }
        if (!done) {
            cout << val[0][0];
            for (int i = 1; i < 4; i++) cout << "." << val[0][i];
            cout << "/32" << endl;
        }
    }
    return 0;
}
