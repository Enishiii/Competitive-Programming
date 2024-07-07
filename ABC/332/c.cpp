#include <iostream>
using namespace std;

class TShirtCalculator {
private:
    int numDays;
    int initialPlainShirts;
    string schedule;

    int minimumShirtsNeeded = 0;
    int plainCount = 0;
    int logoCount = 0;

public:
    void readInput() {
        cin >> numDays >> initialPlainShirts;
        cin >> schedule;
        schedule += '0';
    }

    int calculateMinimumShirtsNeeded() {
        for (int i = 0; i <= numDays; ++i) {
            if (schedule[i] == '0') {
                minimumShirtsNeeded = max(minimumShirtsNeeded, max(plainCount + logoCount - initialPlainShirts, logoCount));
                plainCount = 0, logoCount = 0;
            } else if (schedule[i] == '1') {
                plainCount++;
            } else if (schedule[i] == '2') {
                logoCount++;
            }
        }
        return minimumShirtsNeeded;
    }
};

int main() {
    TShirtCalculator calculator;
    calculator.readInput();

    int result = calculator.calculateMinimumShirtsNeeded();
    cout << result << endl;

    return 0;
}
