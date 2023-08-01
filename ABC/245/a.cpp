/* 問題文
ある日、高橋君はA 時B 分ちょうどに、青木君はC 時D 分1 秒に起きました。
高橋君の起床時刻が青木君より早いならば Takahashi を、そうでないならば Aoki を出力してください。

制約
0≤A≤23
0≤B≤59
0≤C≤23
0≤D≤59
入力はすべて整数である。*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool takahashi = false;

    if (a < c) takahashi = true;
    else if (c < a) takahashi = false;
    else if (b <= d) takahashi = true;

    if (takahashi) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
