/* 問題文
1 以上 N 以下の整数であって、A の倍数でも B の倍数でもないものの総和を求めてください。

制約
1≤N,A,B≤10^9
入力は全て整数 */

#include <iostream>
#include <numeric>

// C++17 or later is required for std::lcm

using namespace std;
using ll = long long;

// Function to find sum of all numbers up to n
ll sumTillN(ll n) {
    return (1 + n) * n / 2;
}

// Function to find sum of all multiples of a till n
ll sumOfMultiplesTillN(ll n, ll a) {
    return sumTillN(n / a) * a;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = sumTillN(n);
    ll lcm = std::lcm(a, b);

    ans -= sumOfMultiplesTillN(n, a);
    ans -= sumOfMultiplesTillN(n, b);
    ans += sumOfMultiplesTillN(n, lcm);

    cout << ans << endl;

    return 0;
}
