#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct BoxData {
    int numBoxes;
    vector<int> initialBoxIndices;
    vector<int> packageWeights;
};

int calculateMinimumMovingCost(BoxData& data) {
    vector<int> maxWeightsInEachBox(data.numBoxes, 0);

    for (int i = 0; i < data.numBoxes; ++i) {
        int targetBoxIndex = data.initialBoxIndices[i] - 1; // 0-indexed にする
        maxWeightsInEachBox[targetBoxIndex] = max(maxWeightsInEachBox[targetBoxIndex], data.packageWeights[i]);
    }

    int totalWeightSum = accumulate(data.packageWeights.begin(), data.packageWeights.end(), 0);
    int maxWeightSum = accumulate(maxWeightsInEachBox.begin(), maxWeightsInEachBox.end(), 0);

    return totalWeightSum - maxWeightSum;
}

int main() {
    BoxData data;
    cin >> data.numBoxes;

    data.initialBoxIndices.resize(data.numBoxes);
    data.packageWeights.resize(data.numBoxes);

    for (int i = 0; i < data.numBoxes; ++i) cin >> data.initialBoxIndices[i];
    for (int i = 0; i < data.numBoxes; ++i) cin >> data.packageWeights[i];

    int minimumCost = calculateMinimumMovingCost(data);

    cout << minimumCost << endl;

    return 0;
}
