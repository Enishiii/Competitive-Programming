#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> t(q);
    vector<bool> state(n, true);

    for (int i = 0; i < q; ++i) {
        cin >> t[i];

        if (state[t[i]-1]) state[t[i]-1] = false;
        else if (!state[t[i]-1]) state[t[i]-1] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (state[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}
