/* ２つの正整数a, bを受け取る。
a>bならaをa-bで置き換え、b>aならbをb-aで置き換える操作をa=bになるまで繰り返す。操作を何回行うかを求める問題。
a, bともに1以上10^18以下の値である。*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 32bit整数におさまらないのでlong longで受け取る
    long long a, b;
    cin >> a >> b;

    /* a = 10^18, b = 1などのときは答えも32bit整数におさまらないのでlong longで宣言する。
    高速に求めるため、問題の通りに１つずつ引いていくのではなく、除算で一気に求める。*/
    long long ans = 0;
    if (a < b) swap(a, b); //　小さい方で割れるようにする
    while(b > 0) {
        ans += a / b;
        a %= b;
        swap(a, b); // bで割った余りのaは、必ずbよりも小さくなるので、大小関係を整理してやる
    }
    cout << ans - 1 << endl;

    return 0;
}
