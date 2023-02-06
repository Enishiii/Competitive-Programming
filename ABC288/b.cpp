#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> t(k);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (i < k) t.push_back(s);
    }
    sort(t.begin(), t.end());
    for (auto& x : t) {
        cout << x << endl;
    }

    return 0;
}
