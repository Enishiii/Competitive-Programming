/* 問題文
N 枚のカードが一列に並べられており、左からi 番目のカード（以下、カード
i とする）には整数Ai が書かれています。
カードの中からいくつかを選んで、書かれた整数の合計が
S となるようにする方法は存在しますか。

制約
1 ≤ N ≤ 60
1 ≤ S ≤ 10000
1 ≤ Ai ≤ 10000
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // dp[i][j]を用意。動的計画法で解く。
    // カード1, 2, ,,, iの中から何枚か選び、選んだカードに書かれた整数の合計をjにすることが可能かどうか
    bool dp[n+1][s+1];
    dp[0][0] = true; // 0枚なら合計は0
    for (int i = 1; i <= s; ++i) dp[0][i] = false;

    // 動的計画法（i >= 1)
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j < a[i]) {
                // i-1番目がtrueなら、i番目は自動的にtrue
                if (dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if (j >= a[i]) {
                // i-1番目の合計に、a[i]を足してjになるならi番目はtrue
                if (dp[i-1][j] == true || dp[i-1][j-a[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if (dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
