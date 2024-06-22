#include <iostream>
#include <vector>
using namespace std;

int main() {
    int candidateCount, voteCount;
    cin >> candidateCount >> voteCount;

    vector<int> candidates(candidateCount, 0);
    int currentWinner = 1;
    int currentWinnerVote = 0;

    for (int i = 0; i < voteCount; ++i) {
        int vote;
        cin >> vote;

        candidates[vote - 1]++;
        if ((candidates[vote - 1] > currentWinnerVote) || (candidates[vote - 1] == currentWinnerVote && vote < currentWinner)) {
            currentWinner = vote;
            currentWinnerVote = candidates[vote - 1];
        }

        cout << currentWinner << '\n';
    }

    return 0;
}
