#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;

    map <char, int> mp;
    map <int, int> mp2;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        mp2[mp[c]]++;
    }

    for (int i = 1; i <= s.size(); ++i) {
        if (!(mp2[i] == 0 || mp2[i] == 2)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
