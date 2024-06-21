#include <iostream>
using namespace std;

struct Scores {
    int takahashiSum = 0;
    int aokiSum = 0;
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

    Scores scores;

    readScores(numOfMatches, scores);

    printWinner(scores);

    return 0;
}
