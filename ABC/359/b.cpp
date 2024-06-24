#include <iostream>
#include <vector>
using namespace std;

vector<int> readInput(int pairCount) {
    int size = pairCount * 2;
    vector<int> array(size);
    for (int i = 0; i < size; ++i) cin >> array[i];
    return array;
}

int countEqualPairs(const vector<int>& colors) {
    int count = 0;
    int size = colors.size();
    for (int i = 0; i < size - 2; ++i) {
        if (colors[i] != colors[i + 2]) continue;

        count++;
    }
    return count;
}

int main() {
    int numberOfPairs;
    cin >> numberOfPairs;

    vector<int> colors = readInput(numberOfPairs);

    int count = countEqualPairs(colors);
    cout << count << endl;

    return 0;
}
