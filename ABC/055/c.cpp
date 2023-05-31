/* 問題文
すぬけくんはパズルが好きです。今日は S と c の形をしたピースを使ったパズルで遊んでいます。 このパズルでは c 型のピースを2 つ組み合わせて S 型のピースを1 つ作ることができます。
すぬけくんは S 型のピースを1 つ、c 型のピースを2 つ組み合わせて Scc という組を可能な限り多く作ることにしました。
すぬけくんがN 個の S 型のピースとM 個の c 型のピースを持っているとき、Scc という組を最大でいくつ作ることが可能か求めなさい。

制約
1≦N,M≦10^12*/

#include <iostream>
using namespace std;

int main() {
    long long numS, numC;
    cin >> numS >> numC;

    long long ans = 0;
    long long neededC = numS * 2;

    if (numC < neededC) {
        ans = numC / 2;
    } else if (numC == neededC) {
        ans = numS;
    } else {
        ans = numS + (numC - neededC) / 4;
    }

    cout << ans << endl;

    return 0;
}
