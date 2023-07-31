/* 問題文
長さ N の数列 A=(A1,A2,…,AN) が与えられます。
Q 個のクエリが与えられるので、順番にすべて処理してください。
q 番目 (1≤q≤Q) のクエリは以下の 3 つのいずれかの形式で、それぞれ次のようなクエリを表します。
・1 xq ：A のすべての要素に xq  を代入する。
・2 iq xq ：Aiq にxq を加える。
・3 iq ：Aiq の値を出力する。

制約
1≤N≤2×10^5
1≤Q≤2×10^5
0≤Ai≤10^9 (1≤i≤N)
q 番目 (1≤q≤Q) のクエリが 2 番目もしくは 3 番目の形式のとき、1≤iq≤N
q 番目 (1≤q≤Q) のクエリが 1 番目もしくは 2 番目の形式のとき、0≤xq≤10^9
3 番目の形式のクエリが存在する
入力される値はすべて整数 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

// 変数宣言と読み取りを同時に行うヘルパー関数
int read_int() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int n = read_int();

    vector<ll> a(n);
    for (auto &num : a) cin >> num;

    ll base_num = 0; // クエリが1の時のxの値を格納する

    // 加算が行われた要素のインデックスと加算量を格納するマップ
    map<int, ll> modification_map;
    for (int i = 0; i < n; ++i) {
        modification_map[i] = a[i];
    }

    int q = read_int();

    for (int i = 0; i < q; ++i) {
        int query_type = read_int();

        switch(query_type) {
            case 1: {
                int x = read_int();

                // 基準値をセットして、それまでの加算量をリセット
                base_num = x;
                modification_map.clear();
                
                break;
            }
            case 2: {
                int index = read_int() - 1; // 0-indexed
                int x = read_int();
                modification_map[index] += x;
                break;
            }
            case 3: {
                int index = read_int() - 1;
                cout << base_num + modification_map[index] << endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
