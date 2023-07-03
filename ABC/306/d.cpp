/* 問題文
高橋くんはレストランで、N 品からなる奇妙なフルコースを楽しむことにしました。
このコースのうち i 番目の料理は以下の通りです。
・Xi =0 の場合、美味しさが Yi  の 解毒剤入り の料理
・Xi =1 の場合、美味しさが Yi  の 毒入り の料理
高橋くんが料理を食べると、高橋くんの状態は以下のように変化します。
最初、高橋くんはお腹を壊していない。
高橋くんが お腹を壊していない 時、解毒剤入り の料理を食べても、高橋くんは お腹を壊していないまま である。
毒入り の料理を食べると、高橋くんは お腹を壊す 。
高橋くんが お腹を壊している 時、解毒剤入り の料理を食べると、高橋くんは お腹を壊していない状態になる 。
毒入り の料理を食べると、高橋くんは 死ぬ 。
コースは以下の流れで進行します。
i=1,…,N についてこの順に、以下の処理を繰り返す。
まず、 i 番目の料理が高橋くんに提供される。
次に、 高橋くんはこの料理に対し「食べる」か「下げてもらう」かを選択する。
「食べる」を選択した場合、高橋くんは i 番目の料理を食べる。食べた料理に応じて高橋くんの状態も変化する。
「下げてもらう」を選択した場合、高橋くんは i 番目の料理を食べない。この料理を後で提供してもらったり何らかの手段で保存したりすることはできない。
最後に、 (状態が変化するなら変化後の時点で) 高橋くんが死んでいない場合、i !=N なら次の料理に進む。
i=N なら高橋くんは生きて退店する。
高橋くんはこのあと重要な仕事があるため、高橋くんは生きて退店しなければなりません。
この条件の下で高橋くんが各料理に対し「食べる」「下げてもらう」を選択したとき、高橋くんが 食べた料理の美味しさの総和として考えられる最大値 ( 但し、何も食べなかった場合は 0 ) を出力してください。

制約
入力は全て整数
1≤N≤3×10^5
Xi  は0,1 のどちらかである。
−10^9 ≤Yi ≤10^9*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

// xの値を、xとyのうち大きい方に更新する関数
void chmax(ll& x, ll y) {
    x = max(x, y);
}

// 入力を読み込み、xとyをペアとして返す関数
pair<vector<int>, vector<int>> read_input(int n) {
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    return make_pair(x, y);
}

ll calculate_maximum_tastiness(const vector<int>& x, const vector<int>& y, int n) {
    // dpテーブルの初期化。行は料理の数+1、列は状態（0: 体内に毒なし、1: 体内に毒あり）
    vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
    dp[0][0] = 0; // 初期状態は、美味しさの総和は0

    for (int i = 0; i < n; ++i) {
        // 食べないを選んだ時、それまでの総和未満になることはない
        chmax(dp[i+1][0], dp[i][0]);
        chmax(dp[i+1][1], dp[i][1]);

        if (x[i] == 0) {
            // 解毒剤入りなら、体内の毒有無に関わらず食べることができる
            chmax(dp[i+1][0], dp[i][0]+y[i]);
            chmax(dp[i+1][0], dp[i][1]+y[i]);
        } else {
            // 毒入りなら、毒が体内にない時のみ食べることができる
            chmax(dp[i+1][1], dp[i][0]+y[i]);
        }
    }

    return max(dp[n][0], dp[n][1]);
}

int main() {
    int n;
    cin >> n;

    auto [x, y] = read_input(n);

    ll ans = calculate_maximum_tastiness(x, y, n);
    cout << ans << endl;

    return 0;
}
