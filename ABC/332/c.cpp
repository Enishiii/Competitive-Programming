#include <iostream>
using namespace std;

int main() {
    int numDays, initialPlainShirts;
    cin >> numDays >> initialPlainShirts;

    string schedule;
    cin >> schedule;
    schedule += '0';

    int maxShirtsNeeded = 0;
    int plainCount = 0, logoCount = 0;

    for (int i = 0; i <= numDays; ++i) {
        if (schedule[i] == '0') {
            maxShirtsNeeded = max(maxShirtsNeeded, max(plainCount + logoCount - initialPlainShirts, logoCount));
            plainCount = 0, logoCount = 0;
        }
        if (schedule[i] == '1') plainCount++;
        if (schedule[i] == '2') logoCount++;
    }
    cout << maxShirtsNeeded << endl;

    return 0;
}
