#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int queryCount;
    cin >> queryCount;

    vector<int> appendedArray;
    vector<int> reversedArray;
    for (int i = 0; i < queryCount; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            appendedArray.push_back(x);
            reversedArray = appendedArray;
            reverse(reversedArray.begin(), reversedArray.end());
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << reversedArray[k-1] << endl;
        }
    }

    return 0;
}
