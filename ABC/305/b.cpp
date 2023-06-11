/* 問題文
直線上に7 個の点A,B,C,D,E,F,G がこの順に並んでいます。
隣り合う点の距離は次の通りです。
    ・点A と点B の距離は3
    ・点B と点C の距離は1
    ・点C と点D の距離は4
    ・点D と点E の距離は1
    ・点E と点F の距離は5
    ・点F と点G の距離は9
2 つの英大文字p,q が与えられます。p,q は A,B,C,D,E,F,G のいずれかで、p!=q が成り立ちます。
点p と点q の間の距離を答えてください。

制約
p,q は A,B,C,D,E,F,G のいずれか
p!=q */

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
    // 各点とその原点Aからの距離をマッピング
    unordered_map<char, int> points {
        {'A', 0},
        {'B', 3},
        {'C', 4},
        {'D', 8},
        {'E', 9},
        {'F', 14},
        {'G', 23}
    };

    char p, q;
    cin >> p >> q;

    // 2つの点間の距離を計算
    int dist = abs(points[p] - points[q]);

    cout << dist << endl;

    return 0;
}
