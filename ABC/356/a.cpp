#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ReverseRange {
    int startIndex;
    int endIndex;
};

vector<int> reversePartially(const vector<int>& array, ReverseRange range) {
    vector<int> result = array;
    reverse(result.begin() + range.startIndex - 1, result.begin() + range.endIndex);
    return result;
}

void print(const vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        if (i != 0) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

int main() {
    int arraySize, startIndex, endIndex;
    cin >> arraySize >> startIndex >> endIndex;

    vector<int> sequence(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        sequence[i] = i + 1;
    }

    ReverseRange range = {startIndex, endIndex};
    vector<int> reversedSequence = reversePartially(sequence, range);

    print(reversedSequence);

    return 0;
}
