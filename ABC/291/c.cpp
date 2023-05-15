#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int x = 0, y = 0;
    set<pair<int, int>> st;
    st.emplace(x, y);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') x++;
        if (s[i] == 'L') x--;
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        st.emplace(x, y);
    }

    if (st.size() == n+1) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}