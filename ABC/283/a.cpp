/* 問題文
整数A,B が与えられます。A^B の値を出力してください。

制約
1≤A,B≤9
入力はすべて整数 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 1;
    for (int i = 0; i < b; ++i) {
        ans *= a;
    }
    cout << ans << endl;

    return 0;
}
