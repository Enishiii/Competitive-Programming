// 問題文
// atcoder の並べ替えである文字列 S が与えられます。
// この文字列 S に対して以下の操作を 0 回以上行います。
//     ・S 中の隣接する 2 文字を選び、入れ替える。
// S を atcoder にするために必要な最小の操作回数を求めてください。

// 制約
// S は atcoder の並べ替えである文字列


#include <iostream>
#include <map>
#include <queue>
using namespace std;

int getMinSwapsToTarget(const string& initial, const string& target) {
    // BFSで最小の操作回数を探索
    // 一回の操作で得られる文字列、2回の操作で得られる文字列、、、と探していくので、最初にtargetとマッチした時が最小の操作回数

    map<string, int> dist;
    queue<string> states;

    dist[initial] = 0;
    states.push(initial);

    while(!states.empty()) {
        string current = states.front();
        states.pop();

        if (current == target) {
            return dist[current];
        }

        for (int i = 1; i < target.size(); ++i) {
            string next = current;
            swap(next[i-1], next[i]);
            if (dist.find(next) == dist.end()) {
                states.push(next);
                dist[next] = dist[current] + 1;
            }
        }
    }
    return -1;
}

int main() {
    string s;
    cin >> s;

    cout << getMinSwapsToTarget(s, "atcoder") << endl;

    return 0;
}
