#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> win(n), p(n);
    iota(p.begin(), p.end(), 0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        win[i] = count(s.begin(), s.end(), 'o');
    }

    stable_sort(p.begin(), p.end(), [&](int i, int j) {
        return win[i] > win[j];
    });

    for (int i = 0; i < n; ++i) {
        cout << p[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
