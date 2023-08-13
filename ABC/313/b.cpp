/* 問題文
N 人の競技プログラマーがいます。順に 人1, 人2,…,人N と呼びます。
競技プログラマーの間には 強さ と呼ばれる関係性があり、相異なる 2 人組 (人X, 人Y) 全てに対して 「人 X は人Y より強い」または「人 Y は人X より強い」のどちらか一方が成り立ちます。
強さ は 推移律 が成り立ちます。言い換えると、相異なる 3 人組 (人X, 人Y, 人Z) 全てに対して次の条件が成り立ちます。
・人 X が人Y よりも強く、かつ人Y が人Z よりも強いとき、人X は人Z よりも強い。
人X が自分以外のどの人Y に対しても「人X は人 Y より強い」という関係が成り立つ時、人 X を 最強のプログラマー と呼びます。(上記の制約下においてそのような人がちょうど 1 人存在することが証明できます)
あなたはM 個の強さに関する情報を知っています。
i 個目の情報は「人Ai  は人Bi より強い」という情報です。
あなたは情報を元に N 人の中から最強のプログラマーを特定することができますか？
最強のプログラマーを特定できる場合はその人の番号を出力してください。特定できない場合、つまり最強のプログラマーとしてあり得る人が複数人いる場合は -1 を出力してください。

制約
2≤N≤50
0≤M≤ N(N−1)/2
​1≤Ai,Bi ≤N
Ai != Bi
​i != j ならば(Ai,Bi) != (Aj,Bj)
全ての情報が正しくなるように、全ての相異なる 2 人組にどちらが強いかを割り当てる方法が少なくとも 1 通り存在する */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 各プログラマーに対して、彼/彼女より強いとされるプログラマーの数を格納する配列
    vector<int> strongerCount(n+1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        strongerCount[b] += 1;
    }

    int strongestProgrammer = -1;
    for (int i = 1; i <= n; ++i) {
        // strongerCountが0のプログラマーが最強
        if (strongerCount[i] == 0) {
            // 既に最強のプログラマーが存在する場合は、最強を特定できない
            if (strongestProgrammer != -1) {
                cout << -1 << endl;
                return 0;
            } else {
                strongestProgrammer = i;
            }
        }
    }
    cout << strongestProgrammer << endl;

    return 0;
}
