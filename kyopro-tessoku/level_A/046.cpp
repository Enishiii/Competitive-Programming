/* 巡回セールスマン問題を貪欲法で解く */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// p点とq点間の距離を求める
double getDistance (const vector<int> &x, const vector<int> &y, int p, int q) {
    return sqrt((x[p] - x[q]) * (x[p] - x[q]) + (y[p] - y[q]) * (y[p] - y[q]));
}

// 貪欲法で経路を求める
void findGreedyPath (int n, vector<int> &x, vector<int> &y, vector<int> &p, vector<bool> &visited) {
    int currentPlace = 0;
    for (int i = 0; i < n; ++i) visited[i] = false;
    p[0] = 1; // 1からスタート
    visited[0] = true;

    for (int i = 1; i < n; ++i) {
        // 初め、minDistは大きい値で初期化しておく
        double minDist = numeric_limits<double>::max();
        int minId = -1;

        // 今いる地点(currentPlace)から一番近い点jを全探索で求める
        for (int j = 0; j < n; ++j) {
            if (visited[j]) continue;
            double newDist = getDistance(x, y, currentPlace, j);
            if (minDist > newDist) {
                minDist = newDist;
                minId = j;
            }
        }

        visited[minId] = true;
        p[i] = minId + 1;
        currentPlace = minId;
    }

    p[n] = 1; // 最終地点は1に戻ってくる
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<int> p(n+1);
    vector<bool> visited(n);

    findGreedyPath(n, x, y, p, visited);

    for (int i = 0; i <= n; ++i) cout << p[i] << endl;

    return 0;
}
