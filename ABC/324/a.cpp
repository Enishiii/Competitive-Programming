// 問題文
// N 個の整数A1,A2,…,AN が与えられます。
// これらの値がすべて等しいならば Yes 、そうでなければ No と出力してください。

// 制約
// 2≤N≤100
// 1≤Ai≤100 (1≤i≤N)
// 入力はすべて整数


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
        if (a[i] != a[i+1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
