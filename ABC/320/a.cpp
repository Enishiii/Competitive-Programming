/*
問題文
正整数A,B が与えられます。
A^B + B^A の値を出力してください。

制約
2 ≤ A ≤ B ≤ 9
入力される数値はすべて整数
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    long long ans = pow(a, b) + pow(b, a);
    cout << ans << endl;

    return 0;
}
