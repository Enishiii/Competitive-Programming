#include <iostream>
#include <vector>
using namespace std;

int countPeopleMeetingCondition(const vector<int>& points, int threshold) {
    int count = 0;
    for (int point : points) {
        if (point >= threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    int peopleCount, threshold;
    cin >> peopleCount >> threshold;

    vector<int> points(peopleCount);
    for (auto& point : points) cin >> point;

    int count = countPeopleMeetingCondition(points, threshold);
    cout << count << endl;

    return 0;
}
