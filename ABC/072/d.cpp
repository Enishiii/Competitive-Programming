/* 問題文
1,2,..,N からなる順列p1,p2,..,pN が与えられます。 次の操作を何回か (0回でもよい) 行うことが出来ます。
・操作: 順列で隣り合う二つの数を選んでスワップする。
何回か操作を行って、任意の1≤i≤N に対してpi != i となるようにしたいです。 必要な操作の最小回数を求めてください。

制約
2≤N≤10^5
p1,p2,..,pN は1,2,..,N の順列である。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    // 問題文の通りに素直にシミュレーションしていく

    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i] == i) {
            swap(p[i], p[i+1]);
            cnt++;
        }
    }

    if (p[n] == n) {
        swap(p[n], p[n-1]);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
