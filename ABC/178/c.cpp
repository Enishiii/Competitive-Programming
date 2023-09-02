/* 問題文
長さ N の整数の列 A1, A2, …, AN であって以下の条件をすべて満たすものはいくつありますか。
    ・0 ≤ Ai ≤ 9
    ・Ai = 0 なるi が存在する。
    ・Ai = 9 なるi が存在する。
ただし、答えはとても大きくなる可能性があるので、10^9 +7 で割った余りを出力してください。

制約
1 ≤ N ≤ 10^6
N は整数 */

#include <iostream>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

// a のb乗を計算し、結果をmodで割った余りを返す関数
ll modular_pow(ll a, ll b) {
    if (b == 0) return 1; // aの0乗は1

    ll half_pow = modular_pow(a, b / 2); // 計算量を削減するために分割統治のアプローチをとる
    half_pow = (half_pow * half_pow) % mod; // a^(b/2)を二乗して、a^bを完成させる

    // bが奇数の場合、上２行の処理だけでは不十分なので追加でaを掛ける
    if (b & 1) half_pow = (half_pow * a) % mod;

    return half_pow;
}

int main() {
    ll n;
    cin >> n;

    // 0~9の10種類の数字をn個並べたものは10^n通り
    // そのうち、0が存在しないものは9^n通り、9が存在しないものは9^n通り
    // また、0, 9がともに存在しないものは8^n通り
    // 包除原理を適用して、0, 9がともに存在するパターンを求める（ベン図を書くとわかりやすい）
    ll ans = modular_pow(10, n) - 2 * modular_pow(9, n) % mod + modular_pow(8, n);
    ans = (ans + mod) % mod; // 結果が負の値にならないようにする

    cout << ans << endl;

    return 0;
}
