#include <iostream>
#include <vector>
using namespace std;

// 任意の型の値を入力
template <typename T>
T readValue() {
    T value;
    cin >> value;
    return value;
}

int main() {
    int queryCount = readValue<int>();

    vector<int> array;
    for (int i = 0; i < queryCount; ++i) {
        int queryType = readValue<int>();

        if (queryType == 1) {
            int value = readValue<int>();

            array.push_back(value);
        } else if (queryType == 2) {
            int position = readValue<int>();

            // array.end()[-position]とも書ける
            cout << array[array.size() - position] << endl;
        }
    }

    return 0;
}
