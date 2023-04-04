#include <iostream>
using namespace std;

int main() {
    int d, t, s;
    cin >> d >> t >> s;

    int dist = t * s;
    if (dist >= d) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
