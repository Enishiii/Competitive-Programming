#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numGiants;
    cin >> numGiants;

    vector<long long> shoulders(numGiants), heads(numGiants);
    for (int i = 0; i < numGiants; ++i) cin >> shoulders[i] >> heads[i];

    long long maxDiffBetweenShoulderAndHead = 0;
    for (int i = 0; i < numGiants; ++i) maxDiffBetweenShoulderAndHead = max(maxDiffBetweenShoulderAndHead, heads[i] - shoulders[i]);

    long long ans = maxDiffBetweenShoulderAndHead;
    for (int i = 0; i < numGiants; ++i) ans += shoulders[i];
    cout << ans << endl;

    return 0;
}
