#include <iostream>
using namespace std;


int main() {
    string s;
    cin >> s;

    if (!isupper(s[0])) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i < s.size(); ++i) {
        if (!islower(s[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
