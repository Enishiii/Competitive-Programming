#include <iostream>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    int index = 0;

    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            // 操作後の先頭文字のインデックスを保持。文字列のサイズを超えないよう、nの余をとる。
            index += n - x;
            index %= n;
        } else {
            // 先頭の文字から、x番目(0-indexedなのでx-1)の文字を出力。文字列のサイズを超えないよう、nの余をとる。
            cout << s[(index + x - 1) % n] << endl;
        }
    }

    return 0;
}
