#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> readArray(int size) {
    vector<int> array(size);
    for (auto& element : array) {
        cin >> element;
    }
    return array;
}

vector<int> createCombinedArray(const vector<int>& array1, const vector<int>& array2) {
    vector<int> combined(array1);
    combined.insert(combined.end(), array2.begin(), array2.end());
    sort(combined.begin(), combined.end());
    return combined;
}

bool hasAdjacentElementsInSet(const vector<int>& array, const set<int>& elements) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        if (elements.contains(array[i]) && elements.contains(array[i+1])) {
            return true;
        }
    }
    return false;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> array1 = readArray(size1);
    vector<int> array2 = readArray(size2);

    set<int> elements(array1.begin(), array1.end());
    vector<int> combined = createCombinedArray(array1, array2);

    cout << (hasAdjacentElementsInSet(combined, elements) ? "Yes" : "No") << endl;

    return 0;
}
