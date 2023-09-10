/*
問題文
1 桁の数字が表示される画面と、ボタンからなる機械があります。
画面に数字k が表示されているとき、ボタンを1 回押すと画面の数字が
ak に変わります。
0 が表示されている状態からボタンを3 回押すと、画面には何が表示されますか？

制約
0 ≤ ai ≤ 9
入力は全て整数である
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a[10];
    for (int i = 0; i < 10; ++i) cin >> a[i];

    int i = 0;
    int ans = 0;
    for (int j = 0; j < 3; ++j) {
        ans = a[i];
        i = ans;
    }
    cout << ans << endl;

    return 0;
}
