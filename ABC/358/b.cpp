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
        long long buyingTime;
        if (t[i] <= currentTime) {
            buyingTime = currentTime + a;
        } else {
            buyingTime = t[i] + a;
        }

        currentTime = buyingTime;

        cout << buyingTime << endl;
    }

    return 0;
}
