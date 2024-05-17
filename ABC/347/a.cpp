#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // nの値チェック（0, 負の値, 数値型か）
    // kの値チェック(0, 負の値, 数値型か)

    vector<int> divisibleNumbers(n);
    for (int i = 0; i < n; ++i) cin >> divisibleNumbers[i];

    for (int number : divisibleNumbers) {
        if (number % k == 0) {
            cout << number / k << " ";
        }
    }
    cout << endl;

    return 0;
}
