#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> s(8);
    for (int i = 0; i < 8; ++i) cin >> s[i];

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i][j] == '*') {
                // jを英小文字に変換
                char c = 'a' + j;
                int num = 8-i;
                cout << c << num << endl;
                return 0;
            }
        }
    }

    return 0;
}
