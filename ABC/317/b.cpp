/*
問題文
ナオヒロ君はN+1 個の連続する整数を1 個ずつ持っていましたが、そのうち
1 個をなくしてしまいました。
残っているN 個の整数が順不同でA1, …, AN として与えられるので、なくした整数を求めてください。
なお、なくした整数が一意に定まるような入力のみが与えられます。

制約
2 ≤ N ≤ 100
1 ≤ Ai ≤ 1000
入力は全て整数である
なくした整数は一意に定まる
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i+1] - a[i] > 1) {
            ans = a[i] + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
