#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t = s;
    for (int i = 0; i < 4; ++i) {
        if (i == 0) t[i] = '0';
        else {
            t[i] = s[i-1];
        }
    }
    cout << t << endl;

    return 0;
}
