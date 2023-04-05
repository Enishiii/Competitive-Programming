#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    long long blue = (long long)a, red = 0;
    // a+b*i <= c*d*i
    // a <= c*d*i - b*i
    // a <= (c*d-b)*i
    // a/(c*d-b) <= i より、c*d-bが非正なら-1, そうでないなら最小のiはa以下になることがわかる。従って、aまでループを回して条件を満たす時のiを求めてやれば良い。
    for (int i = 1; i <= a; ++i) {
        blue += b;
        red += c;
        if (blue <= red*d) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
