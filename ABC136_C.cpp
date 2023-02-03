#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    for (int i = n-2; i >= 0; --i) {
        if (h[i] == h[i+1]+1) h[i]--;
        else if (h[i] > h[i+1]+1) {
            cout << "No" << endl;
            return 0;
        }
        else continue;
    }
    cout << "Yes" << endl;

    return 0;
}
