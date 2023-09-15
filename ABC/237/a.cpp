/*
問題文
整数N が与えられます。N が−2^31 以上かつ2^31 未満ならば Yes を、そうでないならば No を出力してください。

制約
−2^63 ≤ N < 2^63
N は整数である。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (-1 * pow(2, 31) <= n && n < pow(2, 31)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
