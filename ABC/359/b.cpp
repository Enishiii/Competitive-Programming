#include <iostream>
#include <vector>
using namespace std;

vector<int> readInput(int size) {
    vector<int> array(size);
    for (int i = 0; i < size; ++i) cin >> array[i];
    return array;
}

int countEqualPairs(const vector<int>& colors, int size) {
    int count = 0;
    for (int i = 0; i < size - 2; ++i) {
        if (colors[i] != colors[i + 2]) continue;

        count++;
    }
    return count;
}

int main() {
    int numberOfPairs;
    cin >> numberOfPairs;

    int size = numberOfPairs * 2;
    vector<int> colors = readInput(size);

    int count = countEqualPairs(colors, size);
    cout << count << endl;

    return 0;
}
