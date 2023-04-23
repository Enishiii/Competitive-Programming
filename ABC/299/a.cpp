#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int v_first = -1, ast, v_second;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '|') {
            if (v_first < 0) v_first = i;
            else v_second = i;
        }
        if (s[i] == '*') ast = i;
    }

    if (v_first < ast && ast < v_second) cout << "in" << endl;
    else cout << "out" << endl;

    return 0;
}
