/* 問題文
長さ N の数列 A=(a1,…,aN) があります。また、整数 K が与えられます。
あなたは次の操作を 0 回以上何度でも行えます。
・1≤i≤N−K を満たす整数 i を選び、ai とai+K の値を入れ替える。
A を昇順に並べ替えることが出来るかどうかを判定してください。

制約
2≤N≤2×10^5
1≤K≤N−1
1≤ai ≤10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> b(k); // i, i+k, i+2k...をそれぞれ独立した配列に保持していく
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i % k].push_back(a[i]);
    }

    // 降順にソート
    for (int i = 0; i < k; ++i) {
        sort(b[i].rbegin(), b[i].rend());
    }
    sort(a.begin(), a.end());

    vector<int> newArray;
    for (int i = 0; i < n; ++i) {
        // 後ろから新しい配列に突っ込んでいく
        newArray.push_back(b[i % k].back());
        b[i % k].pop_back();
    }

    // 昇順にソートしたaと、新しい配列が等しいならYes
    if (a == newArray) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
