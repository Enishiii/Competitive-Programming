#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < 2 * n - 2; ++i) {
        if (a[i] == a[i + 2]) count++;
    }
    cout << count << endl;

    return 0;
}
