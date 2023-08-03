#include <iostream>
#include <vector>
#include <string>
using namespace std;

constexpr int MOD = 1e9 + 7;
const string TARGET = "chokudai";

int main() {
    string s;
    cin >> s;

    int n = s.size();

    // dp[i][j] := sのi文字目までを使って、chokudaiのj文字目まで選択する方法
    vector<vector<int>> dp(n+1, vector<int>(TARGET.size()+1, 0));

    dp[0][0] = 1; // 下線を全く引かないので、1通り

    // sの0文字目までを使ってchokudaiのi文字目までを選択する方法はない
    for (int i = 1; i <= TARGET.size(); ++i) dp[0][i] = 0;

    // chokudaiの0文字目まで選択するのは、下線を全く引かない1通り
    for (int i = 1; i <= n; ++i) dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= TARGET.size(); ++j) {
            if (s[i-1] == TARGET[j-1]) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][TARGET.size()] << endl;

    return 0;
}
