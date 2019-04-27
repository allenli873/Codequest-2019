#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int grid[9][9];

bool dfs(int x, int y) {
    if (x == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << grid[i][j];
            cout << endl;
        }
        return true;
    }
    if (y == 9) return dfs(x + 1, 0);
    if (grid[x][y] != 0) return dfs(x, y + 1);
    bool good[10];
    for (int i = 0; i < 10; i++) good[i] = 1;
    for (int i = 0; i < 9; i++) {
        if (i != y && grid[x][i] != 0) good[grid[x][i]] = 0;
    }
    for (int i = 0; i < 9; i++) {
        if (i != x && grid[i][y] != 0) good[grid[i][y]] = 0;
    }
    int ic = x / 3 * 3;
    int jc = y / 3 * 3;
    for (int i = ic; i < ic + 3; i++) {
        for (int j = jc; j < jc + 3; j++) {
            if ((i != x || j != y) && grid[i][j] != 0) good[grid[i][j]] = 0;
        }
    }
    vector<int> vec;
    for (int i = 1; i < 10; i++) if (good[i]) vec.push_back(i);
    random_shuffle(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        grid[x][y] = vec[i];
        if (dfs(x, y + 1)) return true;
    }
    grid[x][y] = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c; cin >> c;
                if (c == '_') grid[i][j] = 0;
                else grid[i][j] = c - '0';
            }
        }
        dfs(0, 0);
    }
    return 0;
}
