#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;

    while(true) {
        int x;
        cin >> x;
        if (cin.fail()) break;

        a.push_back(x);
    }

    int n = a.size();
    for (int i = n-1; i >= 0; --i) {
        cout << a[i] << endl;
    }

    return 0;
}
