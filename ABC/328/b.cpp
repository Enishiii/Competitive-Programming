#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isZorome(const string& date) {
    return size(set<char>(date.begin(), date.end())) == 1;
}

int countZoromeDate(const vector<int>& days) {
    int n = days.size();
    int zoromeCount = 0;
    for (int m = 1; m <= n; ++m) {
        string month = to_string(m);
        for (int d = 1; d <= days[m - 1]; ++d) {
            string date = month + to_string(d);
            if (!isZorome(date)) continue;
            zoromeCount++;
        }
    }
    return zoromeCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> days(n);
    for (auto& day : days) cin >> day;

    int zoromeCount = countZoromeDate(days);
    cout << zoromeCount << endl;

    return 0;
}
