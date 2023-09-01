/* 問題文
ある地方に、1 からN の番号がついた N 個の街と、1 から M の番号がついた M 本の道路があります。
i 番目の道路は街 Ai と街Bi を双方向に結び、長さは Ci です。
好きな街からスタートして同じ街を二度以上通らずに別の街へ移動するときの、通る道路の長さの和としてありえる最大値を求めてください。

制約
2 ≤ N ≤ 10
1 ≤ M ≤ N(N−1)/2
​1 ≤ Ai < Bi ≤ N
(Ai ,Bi) は相異なる
1 ≤ Ci ≤ 10^8
入力は全て整数である */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dfsに渡す引数を少なくするためにクラスを導入
class CityGraph {
    private:
        vector<vector<int>> roads;
        vector<int> visitedCities;

    public:
        CityGraph(int n) : roads(n+1, vector<int>(n+1, 0)), visitedCities(n+1, 0) {}

        void addRoad(int a, int b, int c) {
            roads[a][b] = roads[b][a] = c;
        }

        int maxRoadLengthFromCity(int v) {
            return dfs(v, 0);
        }

    private:
        int dfs(int v, int currentSum) {
            visitedCities[v] = 1;
            int currentMax = currentSum;

            for (int i = 1; i <= roads.size(); ++i) {
                if (!visitedCities[i] && roads[v][i]) {
                    currentMax = max(currentMax, dfs(i, currentSum + roads[v][i]));
                }
            }

            visitedCities[v] = 0;
            return currentMax;
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    CityGraph graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.addRoad(a, b, c);
    }

    int maxTotalRoadLength = 0;
    for (int i = 1; i <= n; ++i) {
        maxTotalRoadLength = max(maxTotalRoadLength, graph.maxRoadLengthFromCity(i));
    }
    cout << maxTotalRoadLength << endl;

    return 0;
}
