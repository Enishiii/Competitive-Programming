/* 問題文
N 人のスポーツ選手がいます。
N 人の選手たちには互いに相性の悪い選手のペアがM 組あり、相性の悪い組のうちi (1≤i≤M) 組目はAi 番目の選手とBi 番目の選手です。
あなたは、選手をT チームに分けます。 どの選手もちょうど一つのチームに属さなければならず、どのチームにも少なくとも一人の選手が属さなければなりません。 さらに、どのi=1,2,…,M についても、Ai 番目の選手とBi 番目の選手が同じチームに属していてはいけません。
この条件を満たすチーム分けの方法は何通りあるか求めてください。 ただし、チーム分けの方法が異なるとは、ある二人が存在して、彼らが一方のチーム分けでは同じチームに所属し、もう一方では異なるチームに所属することをいいます。

制約
1≤T≤N≤10
0≤M≤N(N−1)/2
​1≤Ai<Bi≤N (1≤i≤M)
(Ai,Bi) != (Aj,Bj) (1≤i<j≤M)
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

unsigned N, T, M;
vector<unsigned> hate, teams;

// 再帰関数でチーム分け
unsigned dfs(unsigned now) {
    // 最後の選手まで見て T チームに分かれていれば OK
    if (now == N) return size(teams) == T;

    unsigned ans{};

    // すでにあるチームに now 番目の選手を追加する
    for (auto &&team : teams)
        // チームに now 番目の選手と相性の悪い選手がいなければ
        if (!(team & hate[now])) {
            team ^= 1U << now;
            ans += dfs(now + 1);
            team ^= 1U << now;
        }

    // チーム数に余裕があるとき、新しいチームを作る
    if (size(teams) < T) {
        teams.emplace_back(1U << now);
        ans += dfs(now + 1);
        teams.pop_back();
    }

    return ans;
}

int main() {
    using namespace std;
    cin >> N >> T >> M;

    // hate[i] の j ビットめが 1 ⟹ i 番目の選手と j 番目の選手の相性が悪い (0-indexed)
    hate = vector<unsigned>(N);
    for (unsigned i{}, a, b; i < M; ++i) {
        cin >> a >> b;
        hate[--b] |= 1U << --a;
    }

    teams.reserve(T);
    cout << dfs(0) << endl;

    return 0;
}
