#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& x : p) cin >> x.first >> x.second;

    int ans = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                int triangle = (p[j].first-p[i].first)*(p[k].second-p[i].second) - (p[k].first-p[i].first)*(p[j].second-p[i].second);
                if (triangle != 0) ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
