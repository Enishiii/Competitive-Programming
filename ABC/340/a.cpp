#include <iostream>
using namespace std;

struct Range {
    int start;
    int end;
    int step;
};

void printRange(Range range) {
    for (int i = range.start; i <= range.end; i += range.step) {
        cout << i;
        if (i != range.end) cout << " ";
    }
    cout << endl;
}

int main() {
    int start, end, step;
    cin >> start >> end >> step;

    Range range = {start, end, step};
    printRange(range);

    return 0;
}
