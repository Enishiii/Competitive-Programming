#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cnt(n, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[i][c - 'a']++;
        }
    }

    vector<int> minCount(26, 1e9);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            minCount[i] = min(minCount[i], cnt[j][i]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < minCount[i]; ++j) {
            cout << static_cast<char>(i + 'a');
        }
    }
    cout << endl;

    return 0;
}
