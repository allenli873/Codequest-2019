#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool grid[n + 1][10][10];
        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
            char c; cin >> c;
            grid[0][i][j] = c - '0';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    int cnt = 0;
                    for (int l = j - 1; l <= j + 1; l++) {
                        for (int m = k - 1; m <= k + 1; m++) {
                            if (l >= 0 && l < 10 && m >= 0 && m < 10 && (l != j || m != k)) {
                                if (grid[i][l][m]) cnt++;
                            }
                        }
                    }
                    if (grid[i][j][k]) {
                        if (cnt <= 1 || cnt >= 4) grid[i + 1][j][k] = 0;
                        else grid[i + 1][j][k] = 1;
                    } else if (cnt == 3) grid[i + 1][j][k] = 1;
                    else grid[i + 1][j][k] = 0;
                }
            }
        }
        for (int i = 0; i < 10; i++)  {
            for (int j = 0; j < 10; j++) cout << grid[n][i][j];
            cout << endl;
        }
    }
    return 0;
}
