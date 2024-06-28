#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size, lower, upper;
    cin >> size >> lower >> upper;

    vector<int> numbers(size);
    for (auto& number : numbers) cin >> number;

    for (int i = 0; i < size; ++i) {
        cout << clamp(numbers[i], lower, upper) << " \n"[i == size - 1];
    }

    return 0;
}
