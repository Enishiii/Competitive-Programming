#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> initializeIndices(const int& n) {
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    return indices;
}

vector<int> countWins(const int& n) {
    vector<int> wins(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        wins[i] = count(s.begin(), s.end(), 'o');
    }
    return wins;
}

void sortIndices(vector<int>& indices, const vector<int>& wins) {
    stable_sort(indices.begin(), indices.end(), [&](int i, int j) {
        return wins[i] > wins[j];
    });
}

void printResults(const vector<int>& indices) {
    int n = indices.size();
    for (int i = 0; i < n; ++i) {
        cout << indices[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> indices = initializeIndices(n);
    vector<int> wins = countWins(n);

    sortIndices(indices, wins);
    printResults(indices);

    return 0;
}
