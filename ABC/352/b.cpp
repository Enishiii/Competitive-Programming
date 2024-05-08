#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int s_index = 0;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[s_index]) {
            cout << i + 1 << " ";
            s_index++;
        }
    }
    cout << endl;

    return 0;
}
