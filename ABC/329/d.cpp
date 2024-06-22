#include <iostream>
#include <vector>
using namespace std;

int main() {
    int candidateCount, voteCount;
    cin >> candidateCount >> voteCount;

    vector<int> candidates(candidateCount + 1, 0);
    int currentWinner = 1;

    for (int i = 0; i < voteCount; ++i) {
        int vote;
        cin >> vote;

        candidates[vote]++;
        if (candidates[vote] > candidates[currentWinner]) {
            currentWinner = vote;
        } else if (candidates[vote] == candidates[currentWinner]) {
            currentWinner = min(currentWinner, vote);
        }

        cout << currentWinner << '\n';
    }

    return 0;
}
