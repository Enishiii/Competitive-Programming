/*
問題文
数字のみからなる、長さ N の文字列 S が与えられます。
S を並べ替えてできる文字列を十進法の整数として解釈したもののうち、平方数であるようなものがいくつあるか求めてください。
より厳密には、次のようになります。
S の先頭から i 番目 (1≤i≤N) の数字に対応する数を si とします。
(1,…,N) の順列 P=(p1,p2,…,pN) によってi=1∑N s[pi] * 10^(N−i) と書ける整数のうち、平方数であるようなものがいくつあるか求めてください。

制約
1≤N≤13
S は数字のみからなる長さ N の文字列
N は整数
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

string getPaddedAndSortedSquare(long long i, int length) {
    string squared_str = to_string(i * i);

    squared_str.insert(squared_str.begin(), length - squared_str.size(), '0'); // length桁になるよう、先頭に0を追加

    sort(squared_str.begin(), squared_str.end());

    return squared_str;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    sort(s.begin(), s.end());

    int count = 0;

    // 平方数を全探索する。
    // 平方数を文字列にしたもの(squared_str)とsを比べて、どの文字cについても、squared_strにcが含まれる数=sにcが含まれる数であれば、一方を並べ替えてもう一方と等しくできる。
    for (long long i = 0; i * i < pow(10, n); ++i) {
        if (s == getPaddedAndSortedSquare(i, n)) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
