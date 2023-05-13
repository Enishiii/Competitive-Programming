/* 問題文
とある銭湯には、スイッチを押すとT 秒間お湯が出るシャワーがあります。
なお、お湯が出ているときにスイッチを押すと、そのタイミングからT 秒間お湯が出つづけます。 お湯の出る時間がT 秒間延長されるわけではないことに注意してください。
このシャワーの前を、N 人の人がスイッチを押して通り過ぎていきます。
i 人目の人は、1 人目の人がスイッチを押したti 秒後にスイッチを押します。お湯が出る時間の総和は何秒かを求めてください。

制約
1 ≦ N ≦ 200,000
1 ≦ T ≦ 10^9
0 = t1 < t2 < t3 <, ..., < tN−1 < tN ≦ 10^9
T,ti はすべて整数である */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n, T;
    cin >> n >> T;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    // i+1人目がT秒以内に来るならば、お湯は出続ける
    // T秒より経ってから来るならば、お湯はT秒間出て止まる
    // よって、次の人との差分とT秒の小さい方を足し続ける
    long long ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int diff = t[i+1] - t[i];
        ans += min(T, diff);
    }
    ans += T; // 最後の人の押した分を足す
    cout << ans << endl;

    return 0;
}
