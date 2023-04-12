/* 問題文
N 個の正整数a1, a2,...,aNが与えられます。非負整数m に対して、
f(m)=(m mod a1)+(m mod a2)+...+(m mod aN) とします。
ここで、X mod Y はX をY で割った余りを表します。
f の最大値を求めてください。

制約
入力は全て整数である
2 ≤ N ≤ 3000
2 ≤ ai ≤ 10^5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // m = a[1]*a[2]*,,,,＊a[n]とすると、各a[i]についてm mod a[i] = 0となる。これはつまり、各a[i]について(m-1) mod a[i] = a[i]-1となることを意味し、この和が求めたいfの最大値になる。全てを掛け合わせてmを求めるのは値が大きくなりすぎて大変なので、いきなりm-1 mod a[i]の総和を求める。
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] - 1;
    }
    cout << ans << endl;

    return 0;
}
