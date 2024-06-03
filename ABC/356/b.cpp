#include <iostream>
#include <vector>
using namespace std;

vector<int> readRequiredIntakes(int nutrientKinds) {
    vector<int> requiredIntakes(nutrientKinds);
    for (int i = 0; i < nutrientKinds; ++i) {
        cin >> requiredIntakes[i];
    }
    return requiredIntakes;
}

vector<int> readDailyIntakes(int dayCounts, int nutrientKinds) {
    vector<int> dailyIntakes(nutrientKinds, 0);
    for (int i = 0; i < dayCounts; ++i) {
        for (int j = 0; j < nutrientKinds; ++j) {
            int intake;
            cin >> intake;
            dailyIntakes[j] += intake;
        }
    }
    return dailyIntakes;
}

bool areAllNutrientsSufficient(const vector<int>& dailyIntakes, const vector<int>& requiredIntakes) {
    for (int i = 0; i < dailyIntakes.size(); ++i) {
        if (dailyIntakes[i] < requiredIntakes[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int dayCounts, nutrientKinds;
    cin >> dayCounts >> nutrientKinds;

    vector<int> requiredIntakes = readRequiredIntakes(nutrientKinds);

    vector<int> dailyIntakes = readDailyIntakes(dayCounts, nutrientKinds);

    if (areAllNutrientsSufficient(dailyIntakes, requiredIntakes)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
