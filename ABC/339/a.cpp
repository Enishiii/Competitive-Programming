#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int dotPosition = -1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != '.') continue;

        dotPosition = i;
        break;
    }

    cout << s.substr(dotPosition + 1) << endl;

    return 0;
}
