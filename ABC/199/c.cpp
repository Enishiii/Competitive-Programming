// 問題文
// 長さ 2N の文字列 S があります。
// この文字列に対して Q 個のクエリが与えられます。
// i 番目のクエリでは 3 つの整数 Ti,Ai,Bi が与えられるので、以下の処理をします。
//     ・Ti=1 のとき : S のAi 文字目とBi 文字目を入れ替える
//     ・Ti=2 のとき : S の前半N 文字と後半 N 文字を入れ替える(Ai,Bi の値は用いない)
// 例えば S が FLIP のときにこのクエリを処理すると、S は IPFL となる。
// これら Q 個のクエリを与えられた順に全て処理した後の S を出力してください。

// 制約
// 1≤N≤2×10^5
// S は長さ2N の英大文字のみからなる文字列
// 1≤Q≤3×10^5
// Ti は1 または2
// Ti=1 のとき、1≤Ai<Bi≤2N
// Ti=2 のとき、Ai=Bi=0


#include <iostream>
using namespace std;

int adjustIndex(int idx, bool isSwapped, int n) {
    if (isSwapped) {
        if (idx < n) return idx + n;
        else return idx - n;
    }
    return idx;
}

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;

    bool isSwapped = false;

    for (int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;

        if (t == 1) {
            a = adjustIndex(a, isSwapped, n);
            b = adjustIndex(b, isSwapped, n);

            swap(s[a], s[b]);
        } else if (t == 2) {
            isSwapped = !isSwapped;
        }
    }

    if (isSwapped) {
        cout << s.substr(n) + s.substr(0, n) << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}
