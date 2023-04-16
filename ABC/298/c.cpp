#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    const int m = 200005;
    vector<vector<int>> box(m, vector<int>());
    vector<vector<int>> card(m, vector<int>());

    for (int x = 0; x < q; ++x) {
        int t, i;
        cin >> t >> i;
        if (t == 1) {
            int j;
            cin >> j;
            box[j].push_back(i);
            card[i].push_back(j);
        } else if (t == 2) {
            sort(box[i].begin(), box[i].end());
            int s = box[i].size();
            for (int j = 0; j < s; ++j) {
                if (j) cout << ' ';
                cout << box[i][j];
            }
            cout << endl;
        } else if (t == 3) {
            sort(card[i].begin(), card[i].end());
            card[i].erase(unique(card[i].begin(), card[i].end()), card[i].end());
            int s = card[i].size();
            for (int j = 0; j < s; ++j) {
                if (j) cout << ' ';
                cout << card[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
