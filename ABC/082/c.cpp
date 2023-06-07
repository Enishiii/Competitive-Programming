/* 問題文
長さ N の正整数の列 a=(a1,a2,...,aN) が与えられます。 あなたの目標は、a のうちいくつかの要素を取り除き、a を 良い数列 にすることです。
ここで、数列 b が 良い数列 であるとは、次の条件が成り立つことです。
    ・b の各要素x について、b に値x はちょうどx 個含まれる。
例えば、(3,3,3), (4,2,4,1,4,2,4), () (空の数列) は良い数列です。 一方、(3,3,3,3),(2,4,1,4,2) は良い数列ではありません。
a を良い数列にするために取り除くべき要素の個数の最小値を求めてください。

制約
1≤N≤10^5
ai は整数である。
1≤ai ≤10^9 */

#include <iostream>
#include <map>
using namespace std;

const int INITIAL_REMOVAL_COUNT = 0;

int main() {
    int arrayLength;
    cin >> arrayLength;

    // 各数値と出現回数を格納する
    map<int, int> numCountMap;
    for (int i = 0; i < arrayLength; ++i) {
        int inputNum;
        cin >> inputNum;
        numCountMap[inputNum]++;
    }

    int minRemovals = INITIAL_REMOVAL_COUNT;

    for (auto pair : numCountMap) {
        int num = pair.first; // 数値
        int count = pair.second; // 出現数

        // 出現数が数値よりも小さい場合、全て削除する必要がある
        // それ以外の場合は余分な出現数を削除する
        if (count < num) minRemovals += count;
        else minRemovals += count - num;
    }

    cout << minRemovals << endl;

    return 0;
}
