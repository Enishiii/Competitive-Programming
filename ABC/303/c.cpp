/* 問題文
二次元平面の点(0,0) に高橋君がいます。初め、高橋君の体力はH です。また、二次元平面にはM 個の体力を回復するアイテムがあり、i 個目のアイテムは点(xi,yi) に置いてあります。
高橋君は、これからN 回の移動をします。i 回目の移動は以下の方法で行われます。
    1. 今高橋君がいる点を(x,y) とする。体力を1 消費し、S のi 番目の文字Si に応じて以下の点に移動する。
        ・Si が R のとき：(x+1,y)
        ・Si が L のとき：(x−1,y)
        ・Si が U のとき：(x,y+1)
        ・Si が D のとき：(x,y−1)
    2. 高橋君の体力が負になった場合、高橋君は倒れてしまい、移動をやめる。そうでない場合、移動した点にアイテムがあり、かつ高橋君の体力がK 未満ならば、移動した点に置かれたアイテムを消費し、高橋君の体力がK になる。
高橋君が一度も倒れることなくN 回の移動を行えるか判定してください。

制約
1 ≤ N,M,H,K ≤ 2×10^5
S は R, L, U, D からなる長さN の文字列
∣xi∣,∣yi∣ ≤ 2×10^5
(xi,yi) は互いに異なる
S 以外の入力は全て整数 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    // 入力
    int N, M, H, K;
    cin >> N >> M >> H >> K;

    string S;
    cin >> S;

    // アイテムの座標をペアにして、mapでフラグ管理
    map<pair<int, int>, int> item_map;
    for (int i = 0; i < M; i++) {
        pair<int, int> item;
        cin >> item.first >> item.second;
        item_map[item] = 1;
    }

    int x = 0, y = 0; // スタート地点の原点

    for (int i = 0; i < N; i++) {
        // Sの各文字を見て移動
        if (S[i] == 'R') x++;
        else if (S[i] == 'L') x--;
        else if (S[i] == 'U') y++;
        else if (S[i] == 'D') y--;

        // 移動の度に体力を1減らし、負の値になれば終了
        H--;
        if (H < 0) {
            cout << "No\n";
            return 0;
        }

        // 移動先の座標にアイテムがあり、かつHがK未満の時
        if (item_map[{x, y}] && H < K) {
            H = K; // 体力を回復
            item_map[{x, y}] = 0; // アイテムを使用済みにしておく
        }
    }

    cout << "Yes\n";
    return 0;
}
