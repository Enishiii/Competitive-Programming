#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}
