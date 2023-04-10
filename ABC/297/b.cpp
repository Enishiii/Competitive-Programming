#include <iostream>
using namespace std;

int main()
{
    // 入力を受け取る
    string s;
    cin >> s;

    // 各文字のイテレータを格納する変数を用意して、代入していく
    int x = -1, y = -1, a = -1, b = -1, c = -1;
    for (int i = 0; i < 8; ++i) {
        if (s[i] == 'B') {
            if (x == -1) x = i;
            if (x != -1) y = i;
        }

        if (s[i] == 'R') {
            if (a == -1) a = i;
            if (a != -1) c = i;
        }
        if (s[i] == 'K') b = i;
    }

    // 問題文の条件を満たすか判定
    if ((a < b && b < c) && (x % 2 != y % 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
