/* 問題文
N 以下の非負整数を大きい方から順にすべて出力してください。

制約
1≤N≤100
N は整数 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; --i) cout << i << endl;

    return 0;
}
