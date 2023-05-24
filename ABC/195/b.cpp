/* 問題文
みかんがたくさんあります。どのみかんの重さもA グラム以上B グラム以下であることがわかっています。（みかんの重さは整数とは限りません。）
この中からいくつかのみかんを選んだところ、選んだみかんの重さの合計がちょうどW キログラムになりました。
選んだみかんの個数として考えられる最小値と最大値を求めてください。ただし、このようなことが起こり得ないなら、かわりにそのことを報告してください。（UNSATISFIABLEと出力）

制約
1≤A≤B≤1000
1≤W≤1000
入力は全て整数*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, w;
    cin >> a >> b >> w;

    w *= 1000; // キログラムからグラムに変換

    // 最小値、最大値を格納する変数
    int mn = 1e9;
    int mx = -1;
    
    const int MX = 1e6; // みかんの個数の考えられる最大値

    // 選ぶ個数を全探索
    for (int n = 1; n <= MX; ++n) {
        // a~bまでは好きな重さにできるので、an ~ bnの中にwがあれば良い。
        if (a * n <= w && w <= b * n) {
            mn = min(mn, n);
            mx = max(mx, n);
        }
    }
    if (mx == -1) cout << "UNSATISFIABLE" << endl;
    else cout << mn << " " << mx << endl;

    return 0;
}
