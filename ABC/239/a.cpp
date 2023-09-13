/*
問題文
地上x メートルの高さから見える水平線は√x(12800000+x) メートル先にあるとするとき、 地上H メートルの高さから見える水平線が何メートル先にあるか求めてください。

制約
1≤H≤10^5
H は整数である
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double h;
    cin >> h;

    double ans = sqrt(h * (12800000 + h));
    printf("%.10f\n", ans);

    return 0;
}
