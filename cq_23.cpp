#include <iostream>
#include <queue>
#define INF 1000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int w, h; cin >> h >> w;
        char grid[w][h];
        int dist[w][h];
        pair<int, int> st;
        pair<int, int> par[w][h];
        bool mark[w][h];
        string s; getline(cin, s);
        for (int i = 0; i < w; i++) {
            getline(cin, s);
            for (int j = 0; j < h; j++) {
                grid[i][j] = ' ';
                dist[i][j] = INF;
                mark[i][j] = 0;
            }
            for (int j = 0; j < s.length(); j++) {
                grid[i][j] = s[j];
                if (s[j] == 'o') st = make_pair(i, j);
            }
        }
        queue<pair<int, int> > q;
        q.push(st);
        dist[st.first][st.second] = 0;
        int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        pair<int, int> bestp;
        int bestd = INF;
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;
            int d = dist[x][y];
            if (d > bestd) break;
            char ch = grid[x][y];
            if (ch == 'X') {
                if (bestd == INF || bestp.first + bestp.second > x + y) {
                    bestp = p;
                    bestd = d;
                }
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int x2 = x + dir[i][0];
                int y2 = y + dir[i][1];
                if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h) {
                    if (dist[x2][y2] == INF && grid[x2][y2] != '#') {
                        par[x2][y2] = make_pair(x, y);
                        dist[x2][y2] = d + 1;
                        q.push(make_pair(x2, y2));
                    }
                }
            }
        }
        pair<int, int> cur = bestp;
        while (cur != st) {
            mark[cur.first][cur.second] = 1;
            cur = par[cur.first][cur.second];
        }
        for (int i = 0; i < w; i++) {
            int last = 0;
            for (int j = 0; j < h; j++) if (grid[i][j] != ' ') last = j;
            for (int j = 0; j <= last; j++) {
                if (grid[i][j] == ' ' && mark[i][j]) cout << '.';
                else cout << grid[i][j];

            } cout << endl;
        }
    }
    return 0;
}
