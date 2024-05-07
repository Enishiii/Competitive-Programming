#include <iostream>
#include <sstream>
using namespace std;

int readInputCount() {
    int inputCount;
    cin >> inputCount;
    return inputCount;
}

string generateOutputString(int inputCount) {
    stringstream ss;
    for (int i = 1; i <= inputCount; ++i) {
        ss << ((i % 3 == 0) ? 'x' : 'o');
    }
    return ss.str();
}

int main() {
    int inputCount = readInputCount();

    string output = generateOutputString(inputCount);

    cout << output << endl;

    return 0;
}
