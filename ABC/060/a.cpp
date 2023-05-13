/* 長さ１〜１０の３つの文字列a, b, cを受け取って、しりとりになっているかを判定する */

#include <iostream>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a.back() == b.front() && b.back() == c.front()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
