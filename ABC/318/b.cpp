#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int area = 0;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            for (int i = 0; i < n; ++i) {
                if (a[i] <= x && x < b[i] && c[i] <= y && y < d[i]) {
                    area++;
                    break; // 1つ以上のシートで覆われているので、次の座標に移動する
                }
            }
        }
    }

    cout << area << endl;

    return 0;
}
