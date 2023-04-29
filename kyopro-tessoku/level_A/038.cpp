/* 問題文
株式会社 KYOPRO-MASTER で働いている太郎君は、今後D 日間の労働計画を立てることにしました。 彼は今期の人事評価を上げるため、より多く働きたいと思っています。 しかし、働きすぎると労働基準監督署に怒られてしまいます。具体的には、i=1,2,...,N に対して、以下の条件を満たす必要があります。

条件
i：Li ～Ri 日目について、最も多く働いた日でもHi 時間以下
太郎君のD 日間の合計労働時間として考えられる最大値は何時間でしょうか。ただし、1 日は24 時間であるものとします。

制約
1 ≤ D ≤ 365
0 ≤ N ≤ 10000
1 ≤ Li ≤ Ri ≤ D
10 ≤ Hi ≤ 24
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力を受け取る
    int d, n;
    cin >> d >> n;
    vector<int> left(n+1), right(n+1), hours(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> left[i] >> right[i] >> hours[i];
    }

    // 各日の労働時間を24時間で初期化
    vector<int> limit(d+1);
    for (int i = 1; i <= d; ++i) limit[i] = 24;

    // left[i]日目からright[i]日目までの労働時間をhours[i]に変更
    for (int i = 1; i <= n; ++i) {
        for (int j = left[i]; j <= right[i]; ++j) {
            limit[j] = min(limit[j], hours[i]);
        }
    }

    // d日間の労働時間の合計を求める
    int ans = 0;
    for (int i = 1; i <= d; ++i) ans += limit[i];
    cout << ans << endl;

    return 0;
}
