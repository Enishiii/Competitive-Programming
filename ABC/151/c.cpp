#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> ac(n);
    vector<int> wa(n);
    for (int i = 0; i < m; ++i) {
        int p;
        string s;
        cin >> p >> s;
        p--;

        if (s == "WA" && !ac[p]) wa[p]++;
        if (s == "AC") ac[p] = true;
    }

    int correct = 0, penalty = 0;
    for (int i = 0; i < n; ++i) {
        if (ac[i]) {
            correct++;
            penalty += wa[i];
        }
    }
    cout << correct << " " << penalty << endl;

    return 0;
}