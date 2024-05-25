#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (charCount[s[i]] == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
