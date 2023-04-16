#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    bool can_transform = false;
    for (int k = 0; k < 4; ++k) {
        vector<vector<int>> rotated_a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated_a[j][n-i-1] = a[i][j];
            }
        }

        bool match = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rotated_a[i][j] == 1 && b[i][j] == 0) {
                    match = false;
                    break;
                }
            }
            if (!match) break;
        }

        if (match) {
            can_transform = true;
            break;
        }

        a = rotated_a;
    }

    if (can_transform) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
