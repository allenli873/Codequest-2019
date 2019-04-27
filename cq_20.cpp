#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct bird {
    string s;
    double a, b, c, d;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        bird known[x], qry[y];
        for (int i = 0; i < x; i++) {
            cin >> known[i].s >> known[i].a >> known[i].b >> known[i].c >> known[i].d;
        }
        for (int i = 0; i < y; i++) {
            cin >> qry[i].a >> qry[i].b >> qry[i].c >> qry[i].d;
            pair<double, string> kvals[x];
            for (int j = 0; j < x; j++) {
                double d = (known[j].a - qry[i].a) * (known[j].a - qry[i].a) + (known[j].b - qry[i].b) * (known[j].b - qry[i].b) + (known[j].c - qry[i].c) * (known[j].c - qry[i].c)  + (known[j].d - qry[i].d) *(known[j].d - qry[i].d) ;
                kvals[j] = make_pair(d, known[j].s);
            }
            sort(kvals, kvals + x);
            map<string, int> cnt;
            for (int j = 0; j < 5; j++) {
                cnt[kvals[j].second]++;
            }
            int mxv = -1, cvm = 0;
            string best = "";
            for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                int cv = it -> second;
                if (cv > mxv) {
                    mxv = cv;
                    best = it -> first;
                    cvm = 1;
                } else if (cv == mxv) cvm++;
            }
            int ix = 5;
            if (cvm > 1) {
                while (true) {
                    mxv = -1;
                    cvm = 0;
                    cnt[kvals[ix++].second]++;
                   for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                       int cv = it -> second;
                       if (cv > mxv) {
                           mxv = cv;
                           best = it -> first;
                           cvm = 1;
                       } else if (cv == mxv) cvm++;
                   }
                   if (cvm == 1) break;
                }
            }
            cout << best << endl;
        }
    }
    return 0;
}
