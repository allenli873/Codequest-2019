#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; getline(cin, str);
    while (n--) {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {
            if ('A' <= str[i] && str[i] <= 'Z') cout << (char) (str[i] + 'a' - 'A');
            else cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
