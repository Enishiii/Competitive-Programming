/* 問題文
整数A,B が与えられるので、A+B の値を答えてください。
但し、この問題はN 択問題であり、i 番の選択肢はCi です。
正解となる 選択肢の番号 を出力してください。

制約
入力は全て整数
1 ≤ N ≤ 300
1 ≤ A,B ≤ 1000
1 ≤ Ci ≤ 2000
Ci は相異なる。すなわち、同じ選択肢が複数存在することはない。
A+B=Ci なるi が丁度1 つ存在する。すなわち、正解となる選択肢が必ずただ1 つ存在する。 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int sum = a + b;
    vector<int> c(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == sum) {
            ans = i + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
