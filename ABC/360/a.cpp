#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s[0] == 'R' || (s[1] == 'R' && s[2] == 'M')) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
