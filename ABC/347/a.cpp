#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a % k == 0) {
            ans.push_back(a / k);
        }
    }

    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
