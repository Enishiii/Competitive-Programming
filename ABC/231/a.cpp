/*
問題文
水圧は水深のみに依存し、水深x [m] の場所ではx/100 [MPa] になるものとします。
水深D [m] の場所の水圧は何 [MPa] ですか？

制約
1≤D≤10000
D は整数である。
*/

#include <iostream>
using namespace std;

int main() {
    double d;
    cin >> d;

    printf("%.5f\n", d/100.0);

    return 0;
}
