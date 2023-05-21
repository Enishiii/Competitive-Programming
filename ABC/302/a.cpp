/* 問題文
体力がA の敵がいます。あなたは、1 回攻撃をすることで敵の体力を
B 減らすことが出来ます。
敵の体力を0 以下にするためには、最小で何回攻撃をする必要があるでしょうか？

制約
1≤A,B≤10^18
A,B は整数である。 */

#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long ans = a / b;
    if (a % b == 0)
        cout << ans << endl;
    else
        cout << ans + 1 << endl;

    return 0;
}
