/* 問題文
横一列に 4 つのマスが並んでいます。
各文字が 0 または 1 である長さ 4 の文字列S が与えられます。
S の i 文字目が 1 であるとき、左から i 番目のマスには 1 人の人がおり、S の i 文字目が 0 であるとき、左からi 番目のマスには人がいません。
全ての人が一斉に、1 つ右隣のマスへ移動します。この移動により、もともと右端のマスにいた人は消えます。
移動後の各マスに人がいるかどうかを、S と同様のルールで文字列として出力してください。

制約
S は 0, 1 のみからなる長さ4 の文字列 */

#include <iostream>
using namespace std;

// 4つのマスの数を表す定数
const int GRID_SIZE = 4;

int main() {
    string initial_status;
    cin >> initial_status;

    string moved_status = initial_status;

    moved_status[0] = '0'; // 最も左のマスは常に空になる

    for (int i = 1; i < GRID_SIZE; ++i) {
        moved_status[i] = initial_status[i-1];
    }

    cout << moved_status << endl;

    return 0;
}
