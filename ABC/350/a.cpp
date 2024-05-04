#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t = s.substr(3, 3);
    int num = stoi(t);

    if (num >= 1 && num < 350 && num != 316) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
