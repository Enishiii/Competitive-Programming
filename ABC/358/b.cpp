#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, a;
    cin >> n >> a;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    long long currentTime = 0;
    for (int i = 0; i < n; ++i) {
        currentTime = max(currentTime, static_cast<long long>(t[i])) + a;
        cout << currentTime << endl;
    }

    return 0;
}
