/*
問題文
a^b を1000000007(=10^9+7) で割った余りを計算してください。

制約
1 ≤ a ≤ 100
1 ≤ b ≤ 10^9
入力はすべて整数
*/

#include <iostream>
using namespace std;

long long power(int a, int b, long long m) {
    long long p = a, ans = 1;

    // b <= 10^9なので、bが2^30を超えることはない
    for (int i = 0; i < 30; ++i) {
        int wari = (1 << i); // 2のi乗を求める

        // bを２進数にした時に、1になる桁であればpを掛ける
        if ((b / wari) % 2 == 1) {
            ans = (ans * p) % m; // 都度余りを取る
        }

        // p = a^1, a^2, a^4, a^8, a^16という風に変化する
        // b回ループを回す必要がなくなり、高速化できる
        p = (p * p) % m;
    }

    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;

    const long long mod = 1e9 + 7;
    cout << power(a, b, mod) << endl;

    return 0;
}
