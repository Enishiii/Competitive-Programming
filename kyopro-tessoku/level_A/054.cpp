/* 問題文
以下の2 種類のクエリを高速に処理する、成績管理システムを実装してください。
クエリ1：生徒x の成績がy 点になったと登録される。
クエリ2：生徒x の成績を答える。
ただし、最初は誰の成績も登録されておらず、与えられるクエリの数は
Q 個であるとします。

入力
Query[i] はi 回目のクエリの情報を表します。クエリ1 の場合は 1 x y、クエリ2 の場合は 2 x という形式で与えられます。
詳しくは入力例をご覧ください。

Q
Query[1]
​:
Query[Q]
​
出力
クエリ2 の答えを、順番に出力してください。

制約
1 ≤ Q ≤ 100,000
成績は0 以上100 以下の整数である
名前は20 文字以下であり、英小文字からなる
クエリ1 では、同じ名前の人が二度登録されることはない
クエリ2 では、その時点で未登録の人の点数を聞くことはない
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> grades;
    for (int i = 0; i < q; ++i) {
        int t;
        string name;
        cin >> t >> name;

        if (t == 1) {
            int score;
            cin >> score;
            grades[name] = score;
        } else if (t == 2) {
            cout << grades[name] << endl;
        }
    }

    return 0;
}
