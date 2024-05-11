#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    string s;
    cin >> s;

    array<int, 26> cnt = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    array<int, 101> cnt2 = {0};
    for (int c : cnt) {
        if (c > 0) cnt2[c]++;
    }

    for (int c : cnt2) {
        if (!(c == 0 || c == 2)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
