#include <iostream>
#include <vector>
using namespace std;

int getInputSize() {
    int size;
    cin >> size;
    return size;
}

vector<string> getInputStrings(int size) {
    vector<string> strings(size);
    for (int i = 0; i < size; ++i) {
        cin >> strings[i];
    }
    return strings;
}

pair<int, int> findDifferentPosition(const vector<string>& firstStrings, const vector<string>& secondStrings) {
    int rows = firstStrings.size();
    int cols = firstStrings.size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (firstStrings[i][j] != secondStrings[i][j]) {
                return {i + 1, j + 1};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int size = getInputSize();

    vector<string> firstStrings = getInputStrings(size);
    vector<string> secondStrings = getInputStrings(size);

    auto differentPosition = findDifferentPosition(firstStrings, secondStrings);

    cout << differentPosition.first << " " << differentPosition.second << endl;

    return 0;
}
