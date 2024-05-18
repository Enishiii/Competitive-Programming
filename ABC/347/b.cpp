#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    vector<int> charCount(26, 0);
    vector<string> patterns;

    for (int i = 0; i < s.size(); ++i) {
        charCount[s[i] - 'a']++;
        if (charCount[s[i] - 'a'] == 1) ans++;

        string tmp = "";
        tmp += s[i];

        for (int j = i + 1; j < s.size(); ++j) {
            tmp += s[j];
            if (count(begin(patterns), end(patterns), tmp)) {
                continue;
            }

            ans++;
            patterns.push_back(tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
