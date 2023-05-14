/* 問題文
正整数からなる長さN の数列A=(A1, …, AN) があります。どの隣接する
2 項の値も相異なります。
この数列に対し、次の操作によりいくつか数を挿入します。
1. 数列A のどの隣接する2 項の差の絶対値も1 であるとき、操作を終了する。
2. 数列A の先頭から見て、隣接する2 項の差の絶対値が1 でない最初の箇所をAi, Ai+1 とする。
    ・Ai < Ai+1 ならば、Ai とAi+1 の間に、Ai+1,A+2,…,Ai+1 −1 を挿入する。
    ・Ai > Ai+1 ならば、Ai とAi+1 の間に、Ai−1, Ai−2, …, Ai+1 +1 を挿入する。
3. 手順 1 に戻る。
操作が終了したときの数列を出力してください。

制約
2 ≤ N ≤ 100
1 ≤ Ai ≤ 100
Ai != Ai+1
入力は全て整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 答え用配列を用意して、前からつっこんでいく
    vector<int> ans;
    for (int i = 0; i < n-1; ++i) {
        ans.push_back(a[i]); // 配列に入れる

        // 問題の条件に従って、素直に実装
        if (abs(a[i+1] - a[i]) > 1) {
            int cur;
            if (a[i] < a[i+1]) {
                cur = a[i] + 1;
                while(cur < a[i+1]) {
                    ans.push_back(cur);
                    cur++;
                }
            } else if (a[i] > a[i+1]) {
                cur = a[i] - 1;
                while(cur > a[i+1]) {
                    ans.push_back(cur);
                    cur--;
                }
            }
        }
    }
    ans.push_back(a[n - 1]); // 上記for文はn-2までしか見ていないので、n-1の要素を追加しておく

    // 出力
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
