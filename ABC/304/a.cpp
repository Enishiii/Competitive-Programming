/* 問題文
人1 、人2 、… 、人N と番号付けられたN 人が、この順番で時計回りに円卓に座っています。 特に、時計回りで人N の次の位置には人1 が座っています。
i=1,2,…,N について、人i の名前はSi 、年齢はAi です。 ここで、異なる
2 人が同じ名前や同じ年齢であることはありません。
年齢が最も小さい人を起点として、座っている位置の時計回りの順番で、
N 人全員の名前を出力してください。

制約
2≤N≤100
N は整数
Si は英小文字のみからなる長さ1 以上10 以下の文字列
i != j ⟹ Si != Sj
​0 ≤ Ai ≤ 10^9
Ai は整数
i != j ⟹ Ai != Aj */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力: 人数
    int numOfPeople;
    cin >> numOfPeople;

    // 入力: 名前と年齢
    vector<string> names(numOfPeople);
    vector<int> ages(numOfPeople);

    int youngestAge = 1e9; // 最年少の年齢を保存（初期値は大きな値で設定）
    int youngestPersonIndex = 0; // 最年少の人のインデックスを保存

    // 全員の名前と年齢を入力し、最年少の人を見つける
    for (int i = 0; i < numOfPeople; ++i) {
        cin >> names[i] >> ages[i];
        if (youngestAge > ages[i]) {
            youngestAge = ages[i];
            youngestPersonIndex = i;
        }
    }

    // 最年少の人を起点に、全員の名前を時計回りに出力
    for (int i = 0; i < numOfPeople; ++i) {
        cout << names[(youngestPersonIndex+i)%numOfPeople] << endl;
    }

    return 0;
}
