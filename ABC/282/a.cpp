/* 問題文
整数 K が与えられます。
英大文字を A から昇順に K 個繋げて得られる文字列を答えてください。

制約
K は 1 以上26 以下の整数 */

#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cout << char('A' + i);
    }
    cout << endl;

    return 0;
}
