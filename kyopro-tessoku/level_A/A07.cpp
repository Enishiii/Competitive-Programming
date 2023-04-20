/* 問題文
ある会社ではD 日間にわたってイベントが開催され，N 人が出席します．参加者i はLi 日目からRi 日目まで出席する予定です． 各日の出席者数を出力するプログラムを作成してください．

制約
1 ≤ D,N ≤ 10^5
1 ≤ Li ≤ Ri ≤ D
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    // 前日比の増減を配列に記録する
    vector<int> diff(d+1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }

    vector<int> ans(d+1);
    ans[0] = 0;
    // 前日比をもとにして、各日の出席者数を求める
    for (int i = 1; i <= d; ++i) ans[i] = ans[i-1] + diff[i];
    for (int i = 1; i <= d; ++i) cout << ans[i] << endl;

    return 0;
}
