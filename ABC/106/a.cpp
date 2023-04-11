#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // a*b で畑全体の面積を求めて、a*1とb*1の道の面積を引く。
    // 最後に２つの道が重なっている部分を2回も引いてしまっているので、その部分の面積1*1を足す
    cout << a*b - a - b + 1 << endl;

    return 0;
}
