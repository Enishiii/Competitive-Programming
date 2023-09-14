/*
問題文
3×3 のマス目に 1 から 9 までの数字が書き込まれており、上から i 行目、左から j 列目
(1≤i≤3,1≤j≤3) に書き込まれている数字は ci,j です。
異なるマスに同じ数字が書き込まれている場合もありますが、同じ数字が縦・横・斜めに 3 つ連続して書き込まれていることはありません。 より厳密には、ci,j について次の条件のすべてが成り立っていることが保証されます。
どの1≤i≤3 についても、ci,1 = ci,2 = ci,3 ではない
どの 1≤j≤3 についても、c1,j = c2,j = c3,j ではない
c1,1 = c2,2 = c3,3 ではない
c3,1 = c2,2 = c1,3 ではない
高橋くんは、それぞれのマスに書かれている数字をランダムな順番で知ります。 高橋くんは、縦・横・斜めの列のうちの 1 つでも次の条件を満たしたときがっかりします。
はじめに知ったほうの 2 マスに書かれた数字が同じであり、最後に知ったマスに書かれた数字がそれと異なる。
高橋くんががっかりせずにすべてのマスに書かれた数字を知る確率を求めてください。

制約
ci,j ∈{1,2,3,4,5,6,7,8,9} (1≤i≤3,1≤j≤3)
ci,1 = ci,2 = ci,3 ではない (1≤i≤3)
c1,j = c2,j = c3,j ではない (1≤j≤3)
c1,1 = c2,2 = c3,3 ではない
c1,3 = c2,2 = c3,1 ではない
*/

#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    array<int, 9> cells;
    for (auto &&c : cells) cin >> c;

    vector<tuple<int, int, int>> sequences = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // 行
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // 列
        {0, 4, 8}, {2, 4, 6} // 斜め
    };

    array<int, 9> order;
    iota(order.begin(), order.end(), 0);

    int not_disappointing_count = 0;
    const int total_permutations = 362880; // 9!

    do {
        bool is_disappointing = false;

        for (const auto &[a, b, c] : sequences) {
            if ((cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c]) ||
            (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b]) ||
            (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])) {
                is_disappointing = true;
                break;
            }
        }

        if (!is_disappointing) not_disappointing_count++;
        
    } while(next_permutation(order.begin(), order.end()));

    cout << fixed << setprecision(10);
    cout << static_cast<double>(not_disappointing_count) / total_permutations << endl;

    return 0;
}
