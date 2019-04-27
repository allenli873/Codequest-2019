//
// Created by Allen Li on 2019-04-27.
//

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
inline void MAX(T &a, T b) { if (a < b) a = b; }

template<class T>
inline void MIN(T &a, T b) { if (a > b) a = b; }

template<class T>
inline void MODA(T &a, T b) {
	a %= b;
	if (a < 0) a += b;
}

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(20)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define long ll
#define finish(x) return cout << (x) << '\n', 0
#define F0R(i, a) for(int (i)=0;(i)<(a);++(i))
#define FOR(i, a, b) for(int (i)=(a);(i)<(b);++(i))
#define F0Rd(i, a) for(int (i)=a;(i)>=0;--(i))
#define FORd(i, a, b) for(int (i)=a;(i)>=(b);--(i))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define mp make_pair
#define pb push_back
#define pf push_front
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int NINF = -0x3f3f3f40;

int dx[]{-1, -1, 0, 1, 1, 1, 0, -1};
int dy[]{0, -1, -1, -1, 0, 1, 1, 1};

int grid[20][20];
bool vis[20][20];
int main() {
	FAST_IO;
	int t; cin >> t;
	while(t--) {
		F0R(i, 20) F0R(j, 20) grid[i][j] = 10;
		memset(vis, false, sizeof vis);
		int a, b; cin >> a >> b;
		queue<pair<pi, int>> q;
		q.push({{a, b}, 100});
		while(!q.empty()) {
			auto num = q.front(); q.pop();
			if(vis[num.f.f][num.f.s]) continue;
			vis[num.f.f][num.f.s]=true;
			grid[num.f.f][num.f.s] = num.s;
			if(num.s == 25) continue;
			F0R(z, 8) {
				int xc = dx[z]+num.f.f, yc = dy[z]+num.f.s;
				if(xc>=0&&xc<20&&yc>=0&&yc<20) {
					q.push({{xc, yc}, num.s/2});
				}
			}
		}
		F0R(i, 20) {
			F0R(j, 20) {
				cout << grid[i][j] << (j == 19 ? "" : " ");
			}
			cout << '\n';
		}
	}
	//cout << (((94 & 89) & 95) & 92) << '\n';
}

