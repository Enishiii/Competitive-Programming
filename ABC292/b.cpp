#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> check(n);

    for (int i = 0; i < q; ++i) {
        int num, x;
        cin >> num >> x;
        x--;
        if (num == 1) check[x]++;
        else if (num == 2) check[x] += 2;
        else if (num == 3) {
            if (check[x] >= 2) {
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
    }

    return 0;
}