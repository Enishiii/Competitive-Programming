#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = s.substr(0, s.size() - 1) + "4";

    cout << ans << endl;

    return 0;
}
