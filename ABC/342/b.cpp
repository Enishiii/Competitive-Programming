#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        mp[p[i]] = i+1;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (mp[a] > mp[b]) {
            cout << b << endl;
        } else {
            cout << a << endl;
        }
    }

    return 0;
}
