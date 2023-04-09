#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 入力を受け取る
    int n, d;
    cin >> n >> d;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    // 問題文の条件を満たすかどうかを二重ループで全探索して判定。条件を満たせばその時点で処理を打ち切りYesを出力
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (t[j]-t[i] <= d) {
                cout << t[j] << endl;
                return 0;
            }
        }
    }
    // 全探索して条件を満たすものがなければNoを出力
    cout << -1 << endl;

    return 0;
}
