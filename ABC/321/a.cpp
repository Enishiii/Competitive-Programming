/*
問題文
以下の条件を満たす正整数x を 321-like Number と呼びます。
    ・x の各桁を上から見ると狭義単調減少になっている。
    ・すなわち、x がd 桁の整数だとすると、1≤i<d を満たす全ての整数
i について以下の条件を満たす。
        ・(x の上からi 桁目) > (x の上からi+1 桁目)
なお、1 桁の正整数は必ず 321-like Number であることに注意してください。
例えば、321,96410,1 は 321-like Number ですが、123,2109,86411 は 321-like Number ではありません。
N が入力として与えられるので、N が 321-like Number なら Yes 、そうでないなら No と出力してください。

制約
入力は全て整数
1 ≤ N ≤ 99999
*/

#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    for (int i = 0; i < n.size()-1; ++i) {
        if (n[i]-'0' <= n[i+1]-'0') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
