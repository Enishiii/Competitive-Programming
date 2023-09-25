/*
問題文
以下の手順で行われる試験があります。
    ・試験は1 ラウンド目から N ラウンド目までの N ラウンドからなる。
    ・各ラウンドに対し、 0 以上 100 以下の整数でスコアが与えられる。
    ・N ラウンドのスコアのうち、最高スコアと最低スコアを除いた N−2 ラウンドのスコアの合計が最終結果となる。
        ・厳密には、各ラウンドのスコアを昇順に並べた列を S=(S1,S2,…,SN) としたとき、最終結果は S2+S3+⋯+SN−1 となる。
現在、試験のうち N−1 ラウンドが終了し、 i ラウンド目のスコアは Ai でした。最終結果を X 以上とするためにN ラウンド目に取るべきスコアの最小値を出力してください。
但し、N ラウンド目にどのようなスコアを取っても最終結果が X 以上にならない場合、代わりに -1 と出力してください。
なお、 N ラウンド目に取りうるスコアは 0 以上 100 以下の整数であることに注意してください。

制約
入力は全て整数
3 ≤ N ≤ 100
0 ≤ X ≤ 100×(N−2)
0 ≤ Ai ≤ 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> scores(n-1);
    for (int& score : scores)
        cin >> score;

    // 二分探索で条件を満たすスコアを探す
    int low = 0, high = 100;
    while(low <= high) {
        int mid = (low + high) / 2;

        // Nラウンド全てのスコア配列を作る
        vector<int> tempScores = scores;
        tempScores.push_back(mid);

        // 最小値および最大値を取得
        auto [minElement, maxElement] = minmax_element(tempScores.begin(), tempScores.end());
        int minScore = *minElement;
        int maxScore = *maxElement;

        int sum = 0;
        for (const int& score : tempScores)
            sum += score;

        int finalScore = sum - minScore - maxScore;

        if (finalScore >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (low > 100)
        cout << -1 << endl;
    else
        cout << low << endl;

    return 0;
}
