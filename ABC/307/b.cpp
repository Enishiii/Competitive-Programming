/* 問題文
英小文字のみからなるN 個の文字列S1,S2,…,SN が与えられます。
1 以上 N 以下の 相異なる 整数i,j であって、Si  とSj  をこの順に連結した文字列が回文となるようなものが存在するか判定してください。
ただし、長さM の文字列 T が回文であるとは、任意の 1≤i≤M について、T の i 文字目と(M+1−i) 文字目が一致していることをいいます。

制約
2≤N≤100
1≤∣Si∣≤50
N は整数
Si は英小文字のみからなる文字列
Si はすべて異なる。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_palindrome(const string& str) {
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            string concatenated = s[i] + s[j];

            if (is_palindrome(concatenated)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
