#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    set<int> st;
    for (int i = 0; i < n; ++i) st.insert(a[i]);

    int x = 0;
    while(st.count(x)) x++;
    int ans = min(x, k);
    cout << ans << endl;

    return 0;
}