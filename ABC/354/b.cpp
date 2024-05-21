#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> c(n);
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> c[i];
        sum += c[i];
    }

    sort(s.begin(), s.end());
    cout << s[sum % n] << endl;

    return 0;
}
