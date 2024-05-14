#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int left = h[0];
    bool isExists = false;
    int index = -1;

    for (int i = 1; i < n; ++i) {
        if (h[i] > left) {
            isExists = true;
            index = i + 1;
            break;
        }
    }

    cout << index << endl;

    return 0;
}
