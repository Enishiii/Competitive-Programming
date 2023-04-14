/* 問題文
筋力をつけたい高橋君は、AtCoder 社のトレーニング設備で、トレーニングをすることにしました。AtCoder 社のトレーニング設備にはN 個のボタンがついており、ちょうど1 個のボタンが光っています。 ボタンには、1 からN までの番号がついています。 ボタンi が光っているときにそのボタンを押すと、ボタンi の明かりが消え、その後ボタンai が光ります。
i=ai であることもあります。 光っていないボタンを押しても、何も起こりません。最初、ボタン1 が光っています。高橋君は、ボタン2 が光っている状態で、トレーニングをやめたいと思っています。そのようなことは可能かどうか判定し、もし可能なら最低で何回ボタンを押す必要があるかを求めてください。

制約
2 ≦ N ≦ 10^5
1 ≦ ai ≦ N
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    int cnt = 1, cur = a[0];
    vector<bool> checked(n);
    while(cur != 1) {
        cnt++;
        checked[cur] = true;
        cur = a[cur];
        if (checked[cur]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;

    return 0;
}
