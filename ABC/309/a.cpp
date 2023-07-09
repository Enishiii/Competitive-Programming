/* 問題文
1 から9 までの数字が書かれた3×3 の盤面があります。

1 2 3
4 5 6
7 8 9

1 以上9 以下の整数A,B が与えられます。ただし、A<B です。
A が書かれたマスとB が書かれたマスが左右に隣接しているか判定してください。

制約
1≤A<B≤9
A,B は整数である。*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a % 3 != 0 && a + 1 == b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
