#include <iostream>
using namespace std;

int keta_sum(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a <= keta_sum(i) && keta_sum(i) <= b) {
            ans += i;
        }
    }
    cout << ans << endl;

    return 0;
}
