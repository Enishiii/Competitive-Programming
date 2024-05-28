#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;

    while(true) {
        int input;
        cin >> input;

        if (cin.fail()) break;

        numbers.push_back(input);
    }

    int size = numbers.size();
    for (int i = size-1; i >= 0; --i) {
        cout << numbers[i] << endl;
    }

    return 0;
}
