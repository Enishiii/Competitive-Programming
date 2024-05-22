#include <iostream>
#include <string>
using namespace std;

int main() {
    string targetString;
    cin >> targetString;

    if (targetString.front() != '<' || targetString.back() != '>') {
        cout << "No" << endl;
        return 0;
    }

    for (size_t i = 1; i < targetString.size() - 1; ++i) {
        if (targetString[i] != '=') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
