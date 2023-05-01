/* 問題文
今日はN 本の映画が上映されます。i 番目の映画は時刻Li に開始し、時刻
Ri に終了します。
最大いくつの映画を最初から最後まで見ることができますか。
ただし、映画を見終わった直後に次の映画を見始めることはできますが、同時に複数の映画を見ることはできないものとします。

制約
1 ≤ N ≤ 300000
0 ≤ Li < Ri ≤ 86400
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力を受け取る
    int n;
    cin >> n;
    vector<int> start(n+1), finish(n+1);
    vector<pair<int, int>> tmp; // ソートするための一時変数
    for (int i = 1; i <= n; ++i) {
        cin >> start[i] >> finish[i];
        tmp.push_back(make_pair(finish[i], start[i]));
    }

    // 終了時刻が早い順にソート（->貪欲法で解く）
    sort(tmp.begin(), tmp.end());
    for (int i = 1; i <= n; ++i) {
        finish[i] = tmp[i-1].first;
        start[i] = tmp[i-1].second;
    }

    // 終了時刻が早いものから貪欲に取っていく（currentTimeは現在時刻）
    int currentTime = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (currentTime <= start[i]) {
            currentTime = finish[i];
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
