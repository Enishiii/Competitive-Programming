/*
問題文
3 つの数字x,y,z をこの順に並べてできる3 桁の整数をxyz と表すことにします。
どの桁も0 でない3 桁の整数abc が与えられるので、abc+bca+cab を求めてください。

制約
abc は どの桁も0 でない3 桁の整数
*/

#include <iostream>
using namespace std;

int main() {
    int input_number;
    cin >> input_number;

    // 入力された数から各桁の数字を取り出す
    int a = input_number / 100; // 100の位
    int b = input_number / 10 % 10; // 10の位
    int c = input_number % 10; // 1の位

    // ローテートした数を生成
    int bca = (b * 100 + c * 10 + a);
    int cab = (c * 100 + a * 10 + b);

    int ans = input_number + bca + cab;
    cout << ans << endl;

    return 0;
}
