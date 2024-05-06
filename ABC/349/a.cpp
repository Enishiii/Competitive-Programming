#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int x;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        sum += x;
    }

    if (sum < 0) cout << 0 - sum << endl;
    else cout << -sum << endl;

    return 0;
}
