#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    for (int w = 1; w < s.size(); ++w) {
        for (int c = 0; c < w; ++c) {
            string current = "";
            for (int j = c; j < s.size(); j += w) {
                current += s[j];
            }

            if (current == t) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
