#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int personCount;
    cin >> personCount;

    vector<int> personPositions(personCount);
    map<int, int> personIndexMap;
    for (int i = 0; i < personCount; ++i) {
        cin >> personPositions[i];
        personIndexMap[personPositions[i]] = i + 1;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; ++i) {
        int personA, personB;
        cin >> personA >> personB;

        if (personIndexMap[personA] > personIndexMap[personB]) {
            cout << personB << endl;
        } else {
            cout << personA << endl;
        }
    }

    return 0;
}
