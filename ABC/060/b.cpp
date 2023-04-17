// aの倍数で、bで割った余りがcになるような数が存在するかを判定するプログラム

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // TLEにならない程度にaの倍数を全て調べ上げる
    const int loop_num = 10000000;
    for (int i = 1; i < loop_num; ++i) {
        if (a*i % b == c) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
