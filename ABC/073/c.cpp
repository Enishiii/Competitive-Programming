/* 問題文
あなたは、joisinoお姉ちゃんと以下のようなゲームをしています。
最初、何も書いていない紙がある。joisinoお姉ちゃんが一つの数字を言うので、その数字が紙に書いてあれば紙からその数字を消し、書いていなければその数字を紙に書く。これをN 回繰り返す。その後、紙に書かれている数字がいくつあるかを答える。
joisinoお姉ちゃんが言った数字が、言った順番にA1,...,ANとして与えられるので、ゲーム終了後に紙に書かれている数字がいくつあるか答えてください。

制約
1 ≦ N ≦ 100000
1 ≦ Ai ≦ 1000000000(=10^9)
入力は全て整数である。
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    // mapで各数字が何回出てくるかを数えておく
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mp[a]++;
    }

    // 個数が奇数個ある数字を数える。
    for (auto p : mp) {
        if (p.second % 2 != 0) ans++;
    }
    cout << ans << endl;

    return 0;
}


/* 別解
setを使って管理する。countとeraseを使って、問題文の通りに実装できる
int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (s.count(x)) s.erase(x);
        else s.insert(x);
    }
    cout << s.size() << endl;

    return 0;
}
*/
