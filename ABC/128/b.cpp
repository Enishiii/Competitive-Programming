#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> s[i] >> p[i];

    vector<int> ans;
    for (int i = 0; i < n; ++i) ans[i] = i;

    sort(ans.begin(), ans.end(), [&](int a, int b){
        if (s[a] != s[b]) return s[a] < s[b];
        return p[a] > p[b];
    });

    for (int i = 0; i < n; ++i) {
        cout << ans[i]+1 << endl;
    }

    return 0;
}