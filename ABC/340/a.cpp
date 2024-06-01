#include <iostream>
using namespace std;

struct Sequence {
    int start;
    int end;
    int step;
};

void printSequence(Sequence sequence) {
    for (int i = sequence.start; i <= sequence.end; i += sequence.step) {
        cout << i;
        if (i != sequence.end) cout << " ";
    }
    cout << endl;
}

int main() {
    int start, end, step;
    cin >> start >> end >> step;

    Sequence sequence = {start, end, step};
    printSequence(sequence);

    return 0;
}
