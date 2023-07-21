/* 問題文
すぬけ君は、文字列の書かれた紙から文字をいくつか切り抜いて、並び替えて別の文字列を作るのが好きです。
明日になると、すぬけ君は文字列S1,...,Sn のうちどれか1 つが書かれた紙がもらえます。 すぬけ君は文字列を作る事をとても楽しみにしているので、どんな文字列を作るか計画を立てることにしました。 ただし、すぬけ君はまだどの文字列が書かれた紙がもらえるかを知らないため、 どの文字列が書かれていた場合にも作れる文字列を考えることにしました。
S1,...,Sn  のどの文字列が書かれていても作れる文字列のうち、最長のものを求めてください。 最長のものが複数ある場合は、辞書順で最小のものを求めてください。

制約
1≤n≤50
i=1,...,n に対して、 1≤∣Si∣≤50
i=1,...,n に対して、 Si  は小文字のアルファベット( a - z )からなる文字列 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cnt(n, vector<int>(26, 0));

    // 各文字列のアルファベットの個数を記録していく
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[i][c - 'a']++;
        }
    }

    // 各アルファベットの、最小値を記録
    vector<int> minCount(26, 1e9);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            minCount[i] = min(minCount[i], cnt[j][i]);
        }
    }

    // 辞書順なので、aから順番に最小値の数だけ出力してやる
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < minCount[i]; ++j) {
            cout << static_cast<char>(i + 'a');
        }
    }
    cout << endl;

    return 0;
}
