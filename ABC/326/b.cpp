#include <iostream>
using namespace std;

int find326LikeNumber(const int& inputValue) {
    for (int hundredsDigit = 1; hundredsDigit <= 9; hundredsDigit++) {
        for (int tensDigit = 0; tensDigit <= 9; tensDigit++) {
            for (int onesDigit = 0; onesDigit <= 9; onesDigit++) {
                int generatedNumber = hundredsDigit * 100 + tensDigit * 10 + onesDigit;
                if (generatedNumber < inputValue) continue;

                if (hundredsDigit * tensDigit != onesDigit) continue;

                return generatedNumber;
            }
        }
    }
}

int main() {
    int inputValue;
    cin >> inputValue;

    int result = find326LikeNumber(inputValue);
    cout << result << endl;

    return 0;
}
