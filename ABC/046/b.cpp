/* 問題文
シカのAtCoDeerくんは一列に並んだN 個のボールをそれぞれK 色のペンキの色のうちのどれかで塗ろうとしています。見栄えが悪くならないように、隣り合ったボールは別の色で塗ることにします。ボールの塗り方としてあり得るものの個数を求めてください。

制約
1≦N≦1000
2≦K≦1000
答えは2^31−1 以下 */

#include <iostream>
using namespace std;

int main() {
    // 入力
    int num_balls, num_colors;
    cin >> num_balls >> num_colors;

    // 隣り合う色は違う色でなければならないので、1番目より後は、color-1通り
    long long total_ways = num_colors;
    for (int i = 1; i < num_balls; ++i) {
        total_ways *= (num_colors - 1);
    }

    cout << total_ways << endl;

    return 0;
}
