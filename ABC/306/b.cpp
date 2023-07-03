/* 問題文
0 と1 からなる長さ64 の数列A=(A0,A1,…,A63) が与えられます。
A0*2^0 + A1*2^1 + ⋯ + A63*2^63 を求めてください。

制約
Ai は0 または1 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // long long(符号付き64bit整数)は最大値が2^63-1
    // unsigned long long(符号なし64bit整数)を使うことに注意
    unsigned long long ans = 0;

    for (int i = 0; i < 64; ++i) {
        unsigned long long a;
        cin >> a;
        ans += a << i; // << iで、2のi乗を表現
    }
    cout << ans << endl;

    return 0;
}
