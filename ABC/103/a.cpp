/* 問題文
3 個のタスクがあり、あなたは全てのタスクを完了させなければなりません。はじめ、任意の1 個のタスクをコスト0 で完了できます。また、i 番目のタスクを完了した直後にコスト∣Aj−Ai∣ でj 番目のタスクを完了できます。ここで∣x∣ はx の絶対値を表します。全てのタスクを完了するのに要する合計コストの最小値を求めてください。

制約
入力は全て整数である
1 ≤ A1,A2,A3 ≤ 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a+3);
    int ans = 0;
    for (int i = 1; i < 3; ++i) {
        ans += abs(a[i]-a[i-1]);
    }
    cout << ans << endl;

    return 0;
}
