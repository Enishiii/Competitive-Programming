#include <iostream>
using namespace std;

const string PREFIX = "L";
const string SUFFIX = "ng";

string generateLongString(int length) {
    return PREFIX + string(length, 'o') + SUFFIX;
}

int main() {
    int numOfOs;
    cin >> numOfOs;

    string results = generateLongString(numOfOs);
    cout << results << endl;

    return 0;
}
