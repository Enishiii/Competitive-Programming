#include <iostream>
#include <vector>
using namespace std;

struct Giant {
    long long shoulderHeight;
    long long headHeight;
};

void readInput(vector<Giant>& giants) {
    int numGiants;
    cin >> numGiants;
    giants.resize(numGiants);
    for (int i = 0; i < numGiants; ++i) {
        cin >> giants[i].shoulderHeight >> giants[i].headHeight;
    }
}

long long calculateMaxHeadShoulderDifference(const vector<Giant>& giants) {
    long long maxHeadShoulderDifference = 0;
    for (const auto& giant : giants) {
        maxHeadShoulderDifference = max(maxHeadShoulderDifference, giant.headHeight - giant.shoulderHeight);
    }
    return maxHeadShoulderDifference;
}

long long sumUpShoulderHeights(const vector<Giant>& giants) {
    long long sum = 0;
    for (const auto& giant : giants) {
        sum += giant.shoulderHeight;
    }
    return sum;
}

int main() {
    vector<Giant> giants;

    readInput(giants);

    long long maxHeadShoulderDifference = calculateMaxHeadShoulderDifference(giants);

    long long sumOfShoulderHeights = sumUpShoulderHeights(giants);

    long long result = maxHeadShoulderDifference + sumOfShoulderHeights;
    cout << result << endl;

    return 0;
}
