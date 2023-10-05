/*
問題文
関数f をf(x)=x^2+2x+3 と定義します。
整数t が入力されるので、f(f(f(t)+t)+f(f(t))) を求めてください。
ただし、答えは2×10^9 以下の整数であることが保証されます。

制約
t は0 以上10 以下の整数である
*/

#include <iostream>
using namespace std;

int f(int x) {
    return x * x + 2 * x + 3;
}

int main() {
    int t;
    cin >> t;

    cout << f(f(f(t)+t) + f(f(t))) << endl;

    return 0;
}
