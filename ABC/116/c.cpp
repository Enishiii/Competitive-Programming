/* 問題文
花壇にN 本の花が咲いており、それぞれ1,2,......,N と番号が振られています。最初、全ての花の高さは0 です。 数列h={h1, h2, h3,......} が入力として与えられます。以下の「水やり」操作を繰り返すことで、すべての
k(1≦k≦N) に対して花k の高さをhk にしたいです。
    ・整数l,r を指定する。l≦x≦r を満たすすべてのx に対して、花x の高さを1 高くする。
条件を満たすための最小の「水やり」操作の回数を求めてください。

制約
1　≦　N　≦　100
0　≦　hi ≦　100
入力はすべて整数である。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reduceHeights(int left, int right, vector<int> &heights, int &totalHeightsRemoved) {
    if (left >= right) return;

    // 最小の高さを見つける
    int minHeight = 1e9;
    for (int i = left; i < right; ++i) {
        minHeight = min(minHeight, heights[i]);
    }

    // 全ての要素を最小値でひき、答えに最小値を加算
    totalHeightsRemoved += minHeight;
    for (int i = left; i < right; ++i) {
        heights[i] -= minHeight;
    }

    // 高さが0になった要素のインデックスと数を保持
    vector<int> zeroIndices;
    zeroIndices.push_back(-1); // 最初の0までの範囲を考慮できるように仮想的な0の位置を追加
    for (int i = left; i < right; ++i) {
        if (heights[i] == 0) zeroIndices.push_back(i);
    }
    zeroIndices.push_back(right); // 最後の0の位置から右端までを考慮できるように追加

    // 0の次の要素から、次に0になる要素まで再帰的にreduceHeights関数を呼び出す
    int numOfZeros = zeroIndices.size();
    for (int i = 0; i < numOfZeros-1; ++i) {
        reduceHeights(zeroIndices[i] + 1, zeroIndices[i+1], heights, totalHeightsRemoved);
    }
}

// 再帰関数で解く
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int ans = 0;
    reduceHeights(0, n, h, ans);
    cout << ans << endl;

    return 0;
}
