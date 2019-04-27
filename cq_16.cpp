#include <iostream>

using namespace std;

int hxv(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else return 10 + c - 'A';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string ctx; cin >> ctx;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            cout << '[';
            for (int j = 0; j < s.length(); j += 2) {
                int a = hxv(s[j]) * 16 + hxv(s[j + 1]);
                int b = hxv(ctx[j]) * 16 + hxv(ctx[j + 1]);
                cout << (char) (a ^ b);
            }
            cout << "]\n";
        }
    }
    return 0;
}
