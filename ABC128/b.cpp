#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<pair<string, int>, int> p[110];
    for (int i = 0; i < n; ++i) {
        string s;
        int q;
        cin >> s >> q;
        p[i] = make_pair(make_pair(s, -q), i);
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        cout << p[i].second+1 << endl;
    }

    return 0;
}