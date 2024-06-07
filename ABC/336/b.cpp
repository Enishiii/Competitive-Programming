#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    // for (int i = 0; ; ++i) {
    //     if (number & (1 << i)) {
    //         cout << i << endl;
    //         return 0;
    //     }
    // }

    int count = 0;
    while(number > 0) {
        if (number % 2 == 1) break;

        count++;
        number /= 2;
    }
    cout << count << endl;

    return 0;
}
