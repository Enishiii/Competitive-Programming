/* 問題文
あなたのパソコンのキーボードには、a キー・Shift キー・CapsLock キーの3 種類のキーがあります。また、CapsLock キーにはランプが付いています。 初め、CapsLock キーのランプは OFF であり、パソコンの画面には空文字列が表示されています。
あなたは、以下の3 種類の操作のうち1 つを選んで実行するということを
0 回以上何度でも行うことができます。
    ・X ミリ秒かけて a キーのみを押す。CapsLock キーのランプが OFF ならば画面の文字列の末尾に a が付け足され、ON ならば A が付け足される。
    ・Y ミリ秒かけて Shift キーと a キーを同時に押す。CapsLock キーのランプが OFF ならば画面の文字列の末尾に A が付け足され、 ON ならば a が付け足される。
    ・Z ミリ秒かけて CapsLock キーを押す。CapsLock キーのランプが OFF ならば ON に、ON ならば OFF に切り替わる。
A と a からなる文字列S が与えられます。画面の文字列をS に一致させるのに必要な最短の時間は何ミリ秒かを求めてください。

制約
1 ≤ X,Y,Z ≤ 10^9
X,Y,Z は整数
1 ≤ ∣S∣ ≤ 3×10^5
S は A と a からなる文字列 */

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    int n = s.size();

    const ll INF = 1e18;

    // dpテーブルの初期化。dp[i][j]はi番目までの文字列でCapsLockの状態がj(0か1)のときの最小時間
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));

    // 初期状態（まだ文字を入力していない時）の定義
    dp[0][0] = 0;

    // dpテーブルの更新
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 2; ++c) {
            int isUpperCase = 0;
            if (s[i] == 'A') isUpperCase = 1;

            for (int nc = 0; nc < 2; ++nc) {
                ll cost = (isUpperCase == nc) ? x : y;
                if (c != nc) cost += z;
                dp[i + 1][nc] = min(dp[i + 1][nc], dp[i][c] + cost);
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;

    return 0;
}
