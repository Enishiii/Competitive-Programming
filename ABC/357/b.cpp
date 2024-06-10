#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string convertCase(string s) {
    int lowerCount = count_if(s.begin(), s.end(), ::islower);
    if (lowerCount * 2 < s.size()) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main() {
    string s;
    cin >> s;

    cout << convertCase(s) << endl;

    return 0;
}
