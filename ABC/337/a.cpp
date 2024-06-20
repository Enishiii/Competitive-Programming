#include <iostream>
using namespace std;

int main() {
    int numOfMatches;
    cin >> numOfMatches;

    int takahashiSum = 0, aokiSum = 0;
    for (int i = 0; i < numOfMatches; ++i) {
        int x, y;
        cin >> x >> y;

        takahashiSum += x;
        aokiSum += y;
    }

    if (takahashiSum > aokiSum) cout << "Takahashi" << endl;
    else if (aokiSum > takahashiSum) cout << "Aoki" << endl;
    else cout << "Draw" << endl;

    return 0;
}
