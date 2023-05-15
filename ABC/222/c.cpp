#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool win(char a, char b) {
    if (a == 'G' && b == 'C') return true;
    if (a == 'C' && b == 'P') return true;
    if (a == 'P' && b == 'G') return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    int n2 = n * 2;
    vector<string> a(n2);
    for (int i = 0; i < n2; ++i) cin >> a[i];
    vector<pair<int, int>> data(n2);
    for (int i = 0; i < n2; ++i) data[i] = pair(0, i);

    for (int mi = 0; mi < m; ++mi) {
        for (int ni = 0; ni < n; ++ni) {
            int i = ni*2, j = ni*2+1;
            int ai = data[i].second, aj = data[j].second;
            if (win(a[ai][mi], a[aj][mi])) data[i].first--;
            if (win(a[aj][mi], a[ai][mi])) data[j].first--;
        }
        sort(data.begin(), data.end());
    }
    for (int i = 0; i < n2; ++i) {
        cout << data[i].second+1 << endl;
    }

    return 0;
}