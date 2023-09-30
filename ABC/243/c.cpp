/*
問題文
xy 座標平面上にN 人の人がいます。人i は(Xi,Yi) にいます。すべての人は異なる地点にいます。
L, R からなる長さN の文字列S があります。
人i はSi = R ならば右向きに、Si = L ならば左向きに、一斉に同じ速度で歩き始めます。ここで、右はx 軸の正の向き、左はx 軸の負の向きです。反対の向きに歩いている人同士が同じ地点に来ることを「衝突」と呼びます。すべての人が歩き続けたとき、衝突は発生しますか？

制約
2 ≤ N ≤ 2×10^5
0 ≤ Xi ≤ 10^9
0 ≤ Yi ≤ 10^9
i != j ならば(Xi,Yi) != (Xj,Yj) である。
Xi,Yi はすべて整数である。
S は L および R からなる長さN の文字列である。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    string s;
    cin >> s;

    unordered_map<int, int> right_min; // 同じy座標で、右を向いている点の最小x座標を保持
    unordered_map<int, int> left_max; // 同じy座標で、左を向いている点の最大x座標を保持

    for (int i = 0; i < n; ++i) { // 各点を走査
        if (s[i] == 'R') {
            // 走査中の点のy座標で左を向いている点が存在し、かつ、その点のx座標が走査中の点よりも大きいとき
            if (left_max.count(y[i]) && x[i] < left_max[y[i]]) {
                cout << "Yes" << endl;
                return 0;
            }
        } else {
            // 走査中の点のy座標で右を向いている点が存在し、かつ、その点のx座標が走査中の点よりも小さいとき
            if (right_min.count(y[i]) && right_min[y[i]] < x[i]) {
                cout << "Yes" << endl;
                return 0;
            }
        }

        // 右を向いている最小のx座標と、左を向いている最大のx座標を更新
        if (s[i] == 'R') {
            if (right_min.count(y[i])) right_min[y[i]] = min(x[i], right_min[y[i]]);
            else right_min[y[i]] = x[i];
        } else {
            if (left_max.count(y[i])) left_max[y[i]] = max(x[i], left_max[y[i]]);
            else left_max[y[i]] = x[i];
        }
    }
    cout << "No" << endl;

    return 0;
}
