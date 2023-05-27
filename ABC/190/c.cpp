/* 問題文
1,2,…,N の番号がついたN 個の皿と、1,2,…,M の番号がついたM 個の条件があります。
条件i は、皿Ai と皿Bi の両方にボールが (1 個以上) 置かれているとき満たされます。
1,2,…,K の番号がついたK 人の人がいて、人i は皿Ci か皿Di のどちらか一方にボールを置きます。
満たされる条件の個数は最大でいくつでしょうか？

制約
入力は全て整数
2 ≤ N ≤ 100
1 ≤ M ≤ 100
1 ≤ Ai < Bi ≤ N
1 ≤ K ≤ 16
1 ≤ Ci < Di ≤ N */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int numDishes, numConditions;
    cin >> numDishes >> numConditions;

    // 構造化束縛を使って、コードを簡潔にかつ読みやすくする
    vector<pair<int, int>> conditions(numConditions);
    for (auto& [dishA, dishB] : conditions) {
        cin >> dishA >> dishB;
    }

    int numChoices;
    cin >> numChoices;

    vector<pair<int, int>> choices(numChoices);
    for (auto& [dishC, dishD] : choices) {
        cin >> dishC >> dishD;
    }

    int maxConditionsMet = 0;

    // 制約が小さいので、全探索で解く
    for (int bit = 0; bit < (1 << numChoices); ++bit) {
        // どちらの皿にボールを置くかを保持する配列を用意
        vector<bool> dishesWithBall(numDishes);

        for (int i = 0; i < numChoices; ++i) {
            const auto [dishC, dishD] = choices[i];
            // ビット演算でどちらにボールを置くかを決定
            dishesWithBall[bit & (1 << i) ? dishC : dishD] = true;
        }

        int conditionsMet = 0;
        for (auto [dishA, dishB] : conditions) {
            if (dishesWithBall[dishA] && dishesWithBall[dishB]) conditionsMet++;
        }

        maxConditionsMet = max(maxConditionsMet, conditionsMet);
    }
    cout << maxConditionsMet << endl;

    return 0;
}
