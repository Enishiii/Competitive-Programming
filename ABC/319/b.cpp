/*
問題文
正整数N が与えられるので、下記で定まる長さ(N+1) の文字列s0s1…sN を出力してください。
    各i=0,1,2,…,N について、
        ・1 以上9 以下のN の約数j であって、i がN/j の倍数であるものが存在するとき、そのようなj のうち最小のものに対応する数字をsi とする。（よって、この場合si は 1 、2 、… 、9 のいずれかである。）
        ・そのようなj が存在しないとき、si は - とする。

制約
1 ≤ N ≤ 1000
入力はすべて整数 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string result = "";
    for (int i = 0; i <= N; i++) {
        bool found = false;
        for (int j = 1; j <= 9; j++) {
            if (N % j == 0 && i % (N / j) == 0) {
                result += to_string(j);
                found = true;
                break;
            }
        }
        if (!found) {
            result += "-";
        }
    }
    cout << result << endl;

    return 0;
}
