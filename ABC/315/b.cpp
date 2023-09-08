/*
問題文
AtCoder 国の暦では、一年は1,2,…,M 番目の月のM か月からなり、そのうち
i 番目の月は1,2,…,Di 番目の日のDi 日からなります。
さらに、 AtCoder 国の一年の日数は奇数、即ちD1 + D2 + ⋯ + DM は奇数です。
一年の真ん中の日は何番目の月の何番目の日か求めてください。
言い換えると、1 番目の月の1 番目の日を1 日目としたときの(D1 + D2 + ⋯ + DM + 1) / 2 日目が何番目の月の何番目の日かを求めてください。

制約
入力は全て整数
1 ≤ M ≤ 100
1 ≤ Di ≤ 100
D1 + D2 + ⋯ + DM は奇数
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> d(m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        sum += d[i];
    }

    int middle = (sum + 1) / 2;

    int month = 1;
    int day = 0;
    for (int i = 0; i < m; ++i) {
        if (middle > d[i]) {
            middle -= d[i];
            month++;
        } else {
            day += middle;
            break;
        }
    }
    cout << month << " " << day << endl;

    return 0;
}
