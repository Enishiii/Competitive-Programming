#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputString;
    cin >> inputString;

    size_t firstPosition = inputString.find('|');
    size_t secondPosition = inputString.find('|', firstPosition + 1);

    string extractedString = inputString.substr(0, firstPosition) + inputString.substr(secondPosition + 1);

    cout << extractedString << endl;

    return 0;
}
