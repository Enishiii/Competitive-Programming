#include <iostream>
using namespace std;


int main() {
    string s;
    cin >> s;

    int lower = 0, upper = 0;
    for (auto& c : s) {
        (islower(c) ? lower : upper)++;
    }

    if (lower < upper) {
        for (auto& c : s) {
            if (islower(c)) c = toupper(c);
        }
    } else {
        for (auto& c : s) {
            if (isupper(c)) c = tolower(c);
        }
    }
    cout << s << "\n";

    return 0;
}
