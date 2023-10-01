/*
問題文
AtCoder 王国では、これからN 日間のお祭りが開催されます。そのうち、
A1 日目、A2 日目、…、AM 日目のM 日では花火が上がります。ここで、お祭りの最終日には花火が上がることが保証されます。(つまり、AM=N が保証されます。)
i=1,2,…,N に対して、以下の問題を解いてください。
    ・i 日目以降で初めて花火が上がるのは、i 日目から数えて何日後か？ただし、i 日目に花火が上がる場合0 日後とする。

制約
1≤M≤N≤2×10^5
1≤A1<A2<⋯<AM=N
入力は全て整数
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> ans(n, -1);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        ans[a[i]-1] = 0;
    }

    int idxZero = 0;
    for (int i = n-1; i >= 0; --i) {
        if (ans[i] == 0) idxZero = i;
        else {
            ans[i] = idxZero - i;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
