#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPalindromeDate(const int& month, const int& day) {
    string date = to_string(month) + to_string(day);
    return size(set<char>(date.begin(), date.end())) == 1;
}

int countPalindromeDates(const vector<int>& daysInMonth) {
    int palindromeDateCount = 0;
    for (int month = 1; month <= daysInMonth.size(); ++month) {
        
        for (int day = 1; day <= daysInMonth[month - 1]; ++day) {
            if (!isPalindromeDate(month, day)) continue;

            palindromeDateCount++;
        }
    }
    return palindromeDateCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> daysInMonth(n);
    for (auto& days : daysInMonth) cin >> days;

    int palindromeDateCount = countPalindromeDates(daysInMonth);
    cout << palindromeDateCount << endl;

    return 0;
}
