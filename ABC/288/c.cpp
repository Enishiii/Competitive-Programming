#include <iostream>
#include <vector>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (uf.same(a, b)) ans++;
        else uf.merge(a, b);
    }
    cout << ans << endl;

    return 0;
}
