/* 問題文
1 からN までの番号が付けられたN 人の人がいます。 それぞれの人にはプログラミング力という整数値が定まっており、人i のプログラミング力は
Pi です。 人1 が最強になるためには、あといくつプログラミング力を上げる必要がありますか？ すなわち、すべてのi != 1 に対してP1+x>Pi を満たすような最小の非負整数x は何ですか？

制約
1≤N≤100
1≤Pi≤100
入力は全て整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // pの2番目の要素から最後の要素までの範囲で最大値を取得
    int max_element = *std::max_element(p.begin()+1, p.end());

    // 1番目の値と比較。1番目が既に最大値の場合、値が負にならないように気をつける
    int result = max(0, max_element - p[0] + 1);

    cout << result << endl;

    return 0;
}
