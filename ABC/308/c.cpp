#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<long long, pair<long long, long long>> &a, const pair<long long, pair<long long, long long>> &b) {
    return (a.second.first * b.second.second > b.second.first * a.second.second) ||
        (a.second.first * b.second.second == b.second.first * a.second.second && a.first < b.first);
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, pair<long long, long long>>> p(n);

    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        p[i] = make_pair(i+1, make_pair(a, a + b));
    }

    sort(p.begin(), p.end(), compare);

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << p[i].first;
    }
    cout << endl;

    return 0;
}
