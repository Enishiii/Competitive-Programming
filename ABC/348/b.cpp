#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        int indexOfMaxEuclideanDistance = -1;
        double maxEuclideanDistance = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            double euclideanDistance = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

            if (maxEuclideanDistance < euclideanDistance) {
                indexOfMaxEuclideanDistance = j + 1;
                maxEuclideanDistance = euclideanDistance;
            }
        }

        cout << indexOfMaxEuclideanDistance << endl;
    }

    return 0;
}
