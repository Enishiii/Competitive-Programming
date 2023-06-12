#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long ans = k * pow((k-1), n-1);
    cout << ans << endl;

    return 0;
}
