#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k >= 2*n-2 && k % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
