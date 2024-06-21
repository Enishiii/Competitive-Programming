#include <iostream>
using namespace std;

const string PREFIX = "L";
const string SUFFIX = "ng";

int main() {
    int n;
    cin >> n;

    string answer = PREFIX + string(n, 'o') + SUFFIX;
    cout << answer << endl;

    return 0;
}
