#include <iostream>
#include <vector>
using namespace std;

int readInt() {
    int inputNumber;
    cin >> inputNumber;
    return inputNumber;
}

int main() {
    int queryCount = readInt();

    vector<int> array;
    for (int i = 0; i < queryCount; ++i) {
        int queryType = readInt();

        if (queryType == 1) {
            int value = readInt();

            array.push_back(value);
        } else if (queryType == 2) {
            int position = readInt();

            // array.end()[-position]とも書ける
            cout << array[array.size() - position] << endl;
        }
    }

    return 0;
}
