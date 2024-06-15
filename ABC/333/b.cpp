#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;

    map<string, int> mp {
        {"AB", 1},
        {"AC", 2},
        {"AD", 2},
        {"AE", 1},
        {"BC", 1},
        {"BD", 2},
        {"BE", 2},
        {"CD", 1},
        {"CE", 2},
        {"DE", 1}
    };

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (mp[s] == mp[t]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
