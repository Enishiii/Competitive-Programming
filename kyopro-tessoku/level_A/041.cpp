/* 問題文
N 枚のタイルがあり、最初はすべて白色で塗られています。太郎君は以下の操作を繰り返すことで、左からi 番目のタイルの色を文字Si（R のとき赤色、 B のとき青色）にしたいです。
・連続する3 つのタイルを赤色で塗り替える
・連続する3 つのタイルを青色で塗り替える
太郎君が目的を達成できるかどうかを判定するプログラムを作成してください。

制約
3 ≤ N ≤ 200000
文字Si は R または B のいずれかである */

#include <iostream>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 同じ文字が3つ続くかを判定する
    // 最後の操作で、必ず３つ連続する箇所が生まれるから
    bool canAchieve = false;
    for (int i = 0; i < n-2; ++i) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            canAchieve = true;
        }
    }

    if (canAchieve) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
