#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '|') {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '*') {
                    for (int k = j+1; k < n; ++k) {
                        if (s[k] == '|') {
                            ok = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (ok) cout << "in" << endl;
    else cout << "out" << endl;

    return 0;
}
