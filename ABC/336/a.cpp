#include <iostream>
using namespace std;

const string PREFIX = "L";
const string SUFFIX = "ng";

int main() {
    int numOfOs;
    cin >> numOfOs;

    string results = PREFIX + string(numOfOs, 'o') + SUFFIX;
    cout << results << endl;

    return 0;
}
