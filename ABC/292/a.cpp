#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        s[i] = toupper(s[i]);
        cout << s[i];
    }
    cout << endl;

    return 0;
}