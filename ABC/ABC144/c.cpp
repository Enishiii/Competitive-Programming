#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 1e18;
    for (long long i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            long long j = n/i;
            ans = min(ans, i+j-2);
        } else continue;
    }
    cout << ans << endl;

    return 0;
}