/* 問題文
配列A=[A1,A2,⋯,AN] が与えられます。大小関係を崩さないように、配列をできるだけ圧縮してください。
ここで圧縮とは、以下の条件をすべて満たす配列
B=[B1,B2,⋯,BN] を求める操作です。なお、このような配列
B は 1 通りに決まります。

条件1 B1,B2,⋯,BN は 1 以上の整数である。
条件2　Ai < Ajであるような組(i,j) については、Bi < Bj である。
条件3　Ai = Ajであるような組(i,j) については、Bi = Bj である。
条件4　Ai > Ajであるような組(i,j) については、Bi > Bj である。
条件5　条件 1～4 を満たす中で、配列B の最大値をできるだけ小さくする。

制約
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 10^9 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        t.push_back(a[i]);
    }

    // 各a[i]について、a[i]以下の数の種類がいくつあるかが答え
    // それを求める下準備として配列aを昇順に並べて重複を削除したtを求める
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    // a[i]がtで何番目かを二分探索を使ってbに入れていく。
    // 0-indexedなので、+1しておく
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
        b[i]++;
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}
