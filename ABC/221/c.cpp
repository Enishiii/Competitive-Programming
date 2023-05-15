#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    while(n) {
        a.push_back(n%10);
        n /= 10;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    int m = a.size();
    do {
        for (int i = 1; i < m; ++i) {
            if (a[0] == 0) continue;
            if (a[i] == 0) continue;
            int l = 0, r = 0;
            for (int j = 0; j < i; ++j) l = l*10+a[j];
            for (int k = i; k < m; ++k) r = r*10+a[k];
            ans = max(ans, l*r);
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;

    return 0;
}