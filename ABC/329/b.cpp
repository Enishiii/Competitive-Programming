#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSecondLargest(const vector<int>& numbers) {
    int largest = *max_element(numbers.begin(), numbers.end());
    int secondLargest = -1;

    for (int number : numbers) {
        if (number == largest) continue;

        secondLargest = max(secondLargest, number);
    }

    return secondLargest;
}

int main() {
    int elementCount;
    cin >> elementCount;

    vector<int> numbers(elementCount);
    for (int i = 0; i < elementCount; ++i) {
        cin >> numbers[i];
    }

    int secondLargest = findSecondLargest(numbers);

    cout << secondLargest << endl;

    return 0;
}
