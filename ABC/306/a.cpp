/* 問題文
長さN の英小文字からなる文字列S が与えられます。
S のi 文字目をSi と記します。
S1,S1,S2,S2,…,SN,SN をこの順に連結した長さ
2N の文字列を出力してください。
例えば、S が beginner のときは bbeeggiinnnneerr と出力してください。

制約
N は1≤N≤50 を満たす整数
S は長さN の英小文字からなる文字列 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 素直に2回ずつ出力する

    for (int i = 0; i < n; ++i) {
        cout << s[i] << s[i];
    }
    cout << endl;

    return 0;
}
