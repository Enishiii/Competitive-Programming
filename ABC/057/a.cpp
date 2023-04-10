/* 24時間表記(0:00~23:59)でa時ちょうどである。b時間後は24時間表記で何時か？
0 <= a, b <= 23 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int time = 0;

    // 例：25時は1時
    if (a+b >= 24) time = a+b-24;
    else time = a+b;

    cout << time << endl;

    return 0;
}
