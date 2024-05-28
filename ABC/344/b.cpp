#include <iostream>
#include <vector>
using namespace std;

vector<int> readArray() {
    vector<int> numbers;

    while(true) {
        int input;
        cin >> input;

        if (cin.fail()) break;

        numbers.push_back(input);
    }

    return numbers;
}

void printReversedArray(const vector<int>& numbers) {
    int size = numbers.size();

    for (int i = size-1; i >= 0; --i) {
        cout << numbers[i] << endl;
    }
}

int main() {
    vector<int> numbers = readArray();

    printReversedArray(numbers);

    return 0;
}
