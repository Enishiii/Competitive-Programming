/* 問題文
二つの文字x とy は以下の3 つの条件のうちどれか1 つを満たすとき、似た文字と呼ばれます。
    ・x とy は同じ文字
    ・x とy の片方が 1 で、もう片方が l
    ・x とy の片方が 0 で、もう片方が o
また、長さN の文字列S とT は以下の条件を満たすとき、似た文字列と呼ばれます。
    ・任意のi (1≤i≤N) について、S のi 番目の文字とT のi 番目の文字は似た文字
英小文字及び数字からなる長さN の文字列S,T が与えられます。
S とT が似た文字列か判定してください。

制約
N は1 以上100 以下の整数
S,T は英小文字及び数字からなる長さN の文字列 */

#include <iostream>
#include <string>
using namespace std;

// 問題文の通りに素直に実装する。１つでも似た文字ではない箇所があれば、Noとなることに注意。

// 似た文字かを判定
bool is_similar_char(char x, char y) {
    if (x == y)
        return true;
    if ((x == '1' && y == 'l') || (x == 'l' && y == '1'))
        return true;
    if ((x == '0' && y == 'o') || (x == 'o' && y == '0'))
        return true;
    return false;
}

// 似た文字列かを判定
bool is_similar_string(const string &s, const string &t) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (!is_similar_char(s[i], t[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    string S, T;

    cin >> N >> S >> T;

    if (is_similar_string(S, T)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
