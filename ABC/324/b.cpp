// 問題文
// 正の整数 N が与えられます。N = 2^x * 3^y を満たす整数x, y が存在するなら Yes 、そうでなければ No と出力してください。

// 制約
// 1≤N≤10^18
// N は整数

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while(n % 2 == 0) {
        n /= 2;
    }

    while(n % 3 == 0) {
        n /= 3;
    }

    if (n == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
