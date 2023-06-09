/* 問題文
数直線と N 個のコマを用いて 1 人でゲームを行います。
はじめ、これらのコマをそれぞれ好きな整数座標に置きます。
このとき、同じ座標に複数のコマを置いても構いません。
以下の移動を繰り返して、座標 X1 ,X2 ,...,XM  のM 個の地点全てをいずれかのコマで訪れることが目的です。
    ・移動: コマを1 つ選び、そのコマの座標を x とする。そのコマを座標 x+1 もしくは座標x−1 に移動する。
ただし、最初にコマを置いた座標はその時点で訪れたとみなします。
目的を達成するまでに移動を行う回数の最小値を求めてください。

制約
入力はすべて整数である。
1≤N≤10^5
1≤M≤10^5
 −10^5 ≤Xi ≤10^5
X1 ,X2,...,XM  は全て異なる。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // コマの数と目標地点の数を入力
    int num_pieces, num_targets;
    cin >> num_pieces >> num_targets;

    // 目標地点の座標を格納する配列
    vector<int> targets(num_targets);
    for (int i = 0; i < num_targets; ++i)
        cin >> targets[i];

    sort(targets.begin(), targets.end());

    // 各地点間の距離を格納する配列
    vector<int> distances(num_targets-1);
    for (int i = 0; i < num_targets-1; ++i)
        distances[i] = targets[i+1] - targets[i];

    sort(distances.begin(), distances.end());

    // 最小の移動回数を計算（距離の最小の部分を足し合わせる）
    long long min_moves = 0;
    for (int i = 0; i < num_targets - num_pieces; ++i) {
        min_moves += distances[i];
    }
    cout << min_moves << endl;

    return 0;
}
