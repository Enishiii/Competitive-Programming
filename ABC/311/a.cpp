#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool a = false;
    bool b = false;
    bool c = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a = true;
        else if (s[i] == 'B') b = true;
        else if (s[i] == 'C') c = true;

        if (a && b && c) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
