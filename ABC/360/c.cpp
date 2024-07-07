#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class BoxOrganizer {
public:
    BoxOrganizer(int numBoxes) : numBoxes_(numBoxes), initialBoxIndices_(numBoxes), packageWeights_(numBoxes) {}

    void readInput() {
        for (int i = 0; i < numBoxes_; ++i) cin >> initialBoxIndices_[i];
        for (int i = 0; i < numBoxes_; ++i) cin >> packageWeights_[i];
    }

    int calculateMinimumMovingCost() const {
        vector<int> maxWeightsInEachBox(numBoxes_);

        for (int i = 0; i < numBoxes_; ++i) {
            int targetBoxIndex = initialBoxIndices_[i] - 1;
            maxWeightsInEachBox[targetBoxIndex] = max(maxWeightsInEachBox[targetBoxIndex], packageWeights_[i]);
        }

        int totalWeightSum = accumulate(packageWeights_.begin(), packageWeights_.end(), 0);
        int maxWeightSum = accumulate(maxWeightsInEachBox.begin(), maxWeightsInEachBox.end(), 0);

        return totalWeightSum - maxWeightSum;
    }

private:
    int numBoxes_;
    vector<int> initialBoxIndices_;
    vector<int> packageWeights_;
};

int main() {
    int numBoxes;
    cin >> numBoxes;

    BoxOrganizer organizer(numBoxes);
    organizer.readInput();

    int minimumMovingCost = organizer.calculateMinimumMovingCost();

    cout << minimumMovingCost << endl;

    return 0;
}
