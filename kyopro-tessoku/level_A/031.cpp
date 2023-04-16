#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long div3 = n / 3;
    long long div5 = n / 5;
    long long div15 = n / 15;

    long long ans = div3 + div5 - div15;
    cout << ans << endl;

    return 0;
}
