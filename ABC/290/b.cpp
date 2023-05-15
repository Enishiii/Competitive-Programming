#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o' && cnt < k) {
            cout << 'o';
            cnt++;
        } else cout << 'x';
    }
    cout << endl;

    return 0;
}