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
    int abc;
    cin >> abc;

    int a = abc / 100;
    int b = abc / 10 % 10;
    int c = abc % 10;

    int bca = (b * 100 + c * 10 + a);
    int cab = (c * 100 + a * 10 + b);

    int ans = abc + bca + cab;
    cout << ans << endl;

    return 0;
}
