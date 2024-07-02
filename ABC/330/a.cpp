#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a < l) continue;

        count++;
    }
    cout << count << endl;

    return 0;
}
