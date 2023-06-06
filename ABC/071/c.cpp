/* 問題文
太さが無視できる棒が N 本あります．
i 番目の棒の長さは Ai  です．
すぬけ君は，これらの棒から 4 本の異なる棒を選び，それらの棒を辺として長方形（正方形を含む）を作りたいです． 作ることができる最大の長方形の面積を求めてください．

制約
4≤N≤10^5
1≤Ai≤10^9
Ai  は整数*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // 入力の棒の数
    int num_of_sticks;
    cin >> num_of_sticks;

    // 長方形を作るための候補となる棒の長さを格納
    vector<int> candidate_sticks;

    // 各棒の長さと出現回数を管理するマップ
    map<int, int> stick_length_count;

    for (int i = 0; i < num_of_sticks; ++i) {
        // 入力
        int stick_length;
        cin >> stick_length;

        stick_length_count[stick_length]++;

        // 同じ長さの棒が２本見つかった場合、長方形作成の候補とする
        if (stick_length_count[stick_length] == 2) {
            stick_length_count[stick_length] = 0;
            candidate_sticks.push_back(stick_length);
        }
    }

    // 候補となる棒の長さを降順にソート
    sort(candidate_sticks.rbegin(), candidate_sticks.rend());

    // 棒が２本以上あるなら、２本の積を出力。ないなら、長方形を作れないので0を出力
    if (candidate_sticks.size() >= 2) {
        cout << (long long)candidate_sticks[0]*candidate_sticks[1] << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
