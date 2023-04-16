#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'x') {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] == 'o') ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
