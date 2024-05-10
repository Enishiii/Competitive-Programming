#include <iostream>
#include <vector>
using namespace std;

int readInputNumber() {
    int inputNumber;
    cin >> inputNumber;
    return inputNumber;
}

vector<int> readTreatments(int treatmentCount) {
    vector<int> treatments(treatmentCount);
    for (int i = 0; i < treatmentCount; ++i) {
        cin >> treatments[i];
    }
    return treatments;
}

int calcTotalTeeth(int toothCount, const vector<int>& treatments) {
    vector<int> toothState(toothCount, 1);
    for (int treatment : treatments) {
        toothState[treatment - 1] = (toothState[treatment - 1] == 0) ? 1 : 0;
    }

    int totalTeeth = 0;
    for (int state : toothState) {
        totalTeeth += (state == 0) ? 0 : 1;
    }
    return totalTeeth;
}

void printTotalTeeth(int totalTeeth) {
    cout << totalTeeth << endl;
}

int main() {
    int toothCount = readInputNumber();
    int treatmentCount = readInputNumber();

    vector<int> treatments = readTreatments(treatmentCount);

    int totalTeethAfterTreatments = calcTotalTeeth(toothCount, treatments);

    printTotalTeeth(totalTeethAfterTreatments);

    return 0;
}
