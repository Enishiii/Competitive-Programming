#include <iostream>
#include <vector>
using namespace std;

int readInt() {
    int input;
    cin >> input;
    return input;
}

vector<int> createPersonIndex(int personCount) {
    vector<int> personIndex(personCount + 1, 0);

    for (int i = 1; i <= personCount; ++i) {
        int person;
        cin >> person;

        personIndex[person] = i;
    }

    return personIndex;
}

void printEarlierPerson(const vector<int>& personIndex, int personA, int personB) {

    if (personIndex[personA] > personIndex[personB]) {
        cout << personB << endl;
    } else {
        cout << personA << endl;
    }

}

int main() {
    int personCount = readInt();

    vector<int> personIndex = createPersonIndex(personCount);

    int queryCount = readInt();

    for (int i = 0; i < queryCount; ++i) {
        int personA = readInt();
        int personB = readInt();

        printEarlierPerson(personIndex, personA, personB);
    }

    return 0;
}
