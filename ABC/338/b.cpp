#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    string s;
    cin >> s;

    map<char, int> charCount;
    for (int i = 0; i < s.size(); ++i) {
        charCount[s[i]]++;
    }

    int maxChar = -1;
    for (int i = 0; i < s.size(); ++i) {
        maxChar = max(maxChar, charCount[s[i]]);
    }

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (charCount[s[i]] == maxChar) {
            cout << s[i] << endl;
            return 0;
        }
    }

    return 0;
}
