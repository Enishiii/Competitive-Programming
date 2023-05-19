/* 問題文
高橋くんは今日も1 人でしりとりの練習をしています。
しりとりとは以下のルールで遊ばれるゲームです。
    ・はじめ、好きな単語を発言する
    ・以降、次の条件を満たす単語を発言することを繰り返す
        ・その単語はまだ発言していない単語である
        ・その単語の先頭の文字は直前に発言した単語の末尾の文字と一致する
高橋くんは、10 秒間にできるだけ多くの単語を発言する練習をしています。
高橋くんが発言した単語の個数N とi 番目に発言した単語Wi が与えられるので、どの発言もしりとりのルールを守っていたかを判定してください。

制約
N は2≤N≤100 を満たす整数である
Wi は英小文字からなる長さ1 以上10 以下の文字列である */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    map<string, int> mp;
    bool is_word_chain_valid = true;

    cin >> w[0];
    mp[w[0]]++;

    for (int i = 1; i < n; ++i) {
        cin >> w[i];
        mp[w[i]]++;
        if (mp[w[i]] > 1 || w[i-1].back() != w[i].front()) {
            is_word_chain_valid = false;
        }
    }

    if (is_word_chain_valid) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
