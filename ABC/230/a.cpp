/*
問題文
AtCoder で定期的に開催されている、国際的な権威があるコンテストである AtCoder Grand Contest (以下、AGC) は今までに54 回開催されてきました。
みなさんがちょうど参加している230 回目の ABC である ABC230 と同様に、 当初はN 回目の AGC のコンテスト名にはN を3 桁になるようにゼロ埋めした数が割り振られていました。(1 回目の AGC は AGC001,2 回目の AGC は AGC002, ...)
ところが、最新の54 回目の AGC のコンテスト名は AGC055 で、回数より
1 大きい数が割り振られています。これは、AGC042 が社会情勢の影響で中止されて欠番となったため、42 回目以降に開催されたコンテストでは開催された回数より1 大きい数が割り振られているからです。(入出力例にある説明も参考にしてください。)
さて、ここで問題です。整数N が与えられるので、N 回目に開催された AGC のコンテスト名を AGCXXX の形式で出力してください。ここで、XXX にはゼロ埋めがなされた3 桁の数が入ります。

制約
1≤N≤54
N は整数である。
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "AGC";
    if (n < 10) ans += "00" + to_string(n);
    if (n >= 10 && n > 41) ans += "0" + to_string(n+1);
    if (n >= 10 && n <= 41) ans += "0" + to_string(n);

    cout << ans << endl;

    return 0;
}
