#include <iostream>
using namespace std;

struct Scores {
    int takahashiSum;
    int aokiSum;
};

void readScores(int numOfMatches, Scores& scores) {
    for (int i = 0; i < numOfMatches; ++i) {
        int takahashiScore, aokiScore;
        cin >> takahashiScore >> aokiScore;

        scores.takahashiSum += takahashiScore;
        scores.aokiSum += aokiScore;
    }
}

void printWinner(const Scores& scores) {
    if (scores.takahashiSum > scores.aokiSum) {
        cout << "Takahashi" << endl;
    } else if (scores.aokiSum > scores.takahashiSum) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    int numOfMatches;
    cin >> numOfMatches;

    Scores scores = {0, 0};

    readScores(numOfMatches, scores);

    printWinner(scores);

    return 0;
}
