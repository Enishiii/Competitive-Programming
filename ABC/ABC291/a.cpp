#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (isupper(s[i])){
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}