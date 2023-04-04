#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }

    int si = b[0][0]/7;
    int sj = b[0][0]%7;
    if (sj+m-1 >= 7) {cout << "No" << endl; return 0;}

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int nb = (si+i) * 7 + (sj+j);
            if (nb != b[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}