#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }

    for (auto a : s) {
        if (s.find(a+x) != s.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
