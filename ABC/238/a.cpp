/*
問題文
2^n > n^2 ですか？

制約
n は1 以上10^9 以下の整数
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (2 <= n && n <= 4) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
