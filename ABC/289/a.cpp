#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') s[i] = '1';
        else if (s[i] == '1') s[i] = '0';
        cout << s[i];
    }
    cout << endl;

    return 0;
}