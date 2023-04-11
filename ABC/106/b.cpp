// 1以上n以下の奇数の中で、約数が8個ある数字は何個あるかを求める
// nは1以上200以下

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // シンプルに二重ループで全探索する
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        int cnt = 0; // 約数の個数をカウント
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) cnt++;
        }
        if (cnt == 8) ans++;
    }
    cout << ans << endl;

    return 0;
}
