/* 問題文
高橋君は医者のすぬけ君から N 種類の薬を処方されました。
i 種類目の薬は(処方された日を含めて) ai 日間、毎日 bi 錠ずつ飲む必要があります。また、高橋君はこれ以外の薬を飲む必要がありません。
薬を処方された日を 1 日目とします。
1 日目以降で、初めて高橋君がその日に飲む必要がある薬が K 錠以下になるのは何日目かを求めてください。

制約
1≤N≤3×10^5
0≤K≤10^9
 1≤ai,bi ≤10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    // 各薬の日数と錠数をpairとして格納
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end()); // 日数で昇順ソート

    // 全部の薬の総錠数を計算
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += p[i].second;
    }

    if (sum <= k) cout << 1 << endl;
    else {
        // 錠数が上限以下になるまで、日数が少ない薬から順に引いていく
        for (int i = 0; i < p.size(); ++i) {
            if (sum <= k) {
                cout << p[i-1].first + 1 << endl;
                return 0;
            }
            sum -= p[i].second;
        }
        // 全部の薬を飲み終えても錠数が上限以下にならない場合、最後の薬を飲み終えた次の日を出力
        cout << p.back().first + 1 << endl;
    }

    return 0;
}
