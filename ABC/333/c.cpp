#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX_DIGITS = 12;

    vector<long long> repunits(MAX_DIGITS);
    for (int i = 0; i < MAX_DIGITS; ++i) {
        repunits[i] = stoll(string(i + 1, '1'));
    }

    set<long long> sums;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        for (int j = 0; j < MAX_DIGITS; ++j) {
            for (int k = 0; k < MAX_DIGITS; ++k) {
                long long sum = repunits[i] + repunits[k] + repunits[j];
                sums.insert(sum);
            }
        }
    }

    auto it = sums.begin();
    advance(it, n-1);

    cout << *it << endl;

    return 0;
}
