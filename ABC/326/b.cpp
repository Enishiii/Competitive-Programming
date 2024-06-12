#include <iostream>
using namespace std;

int main() {
    int inputValue;
    cin >> inputValue;

    for (int hundredsDigit = 1; hundredsDigit <= 9; hundredsDigit++) {
        for (int tensDigit = 0; tensDigit <= 9; tensDigit++) {
            for (int onesDigit = 0; onesDigit <= 9; onesDigit++) {
                int generatedNumber = hundredsDigit * 100 + tensDigit * 10 + onesDigit;
                if (generatedNumber >= inputValue && hundredsDigit * tensDigit == onesDigit) {
                    cout << generatedNumber << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
