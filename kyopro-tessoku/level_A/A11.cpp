// 二分探索の練習問題。配列Aは昇順に入力される。

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = n - 1;
    while(l <= r) {
        int i = (l + r) / 2;
        if (a[i] == x) {
            cout << i + 1 << endl;
            return 0;
        } else if (a[i] < x) {
            l = i + 1;
        } else if (a[i] > x) {
            r = i - 1;
        }
    }

    return 0;
}
