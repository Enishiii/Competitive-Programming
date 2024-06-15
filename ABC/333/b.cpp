#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areCharactersAdjacent(char x, char y) {
    if (x > y) swap(x, y);
    return (y - x == 1) || (y - x == 4);
}

int main() {
    char a, b, c, d;
    cin >> a >> b >> c >> d;

    if (areCharactersAdjacent(a, b) == areCharactersAdjacent(c, d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
