#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool Subset(const vector<int> &small, const vector<int> &large) {
    unordered_set<int> largeSet(large.begin(), large.end());

    for (int num : small) {
        if (largeSet.find(num) == largeSet.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    vector<vector<int>> features(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int C;
        cin >> P[i] >> C;
        for (int j = 0; j < C; j++) {
            int F;
            cin >> F;
            features[i].push_back(F);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j || P[i] < P[j]) continue;

            bool isSubset = true;
            vector<int> fi = features[i];
            vector<int> fj = features[j];

            if (!Subset(fi, fj)) isSubset = false;

            bool hasExtraFeature = false;
            if (fj.size() > fi.size()) hasExtraFeature = true;

            if (isSubset && (hasExtraFeature || P[i] > P[j])) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}
