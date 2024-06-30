#include <iostream>
using namespace std;

int main() {
    int months, days;
    cin >> months >> days;

    int year, month, day;
    cin >> year >> month >> day;

    day++;
    if (day > days) {
        month++;
        day = 1;
    }
    if (month > months) {
        year++;
        month = 1;
    }

    cout << year << " " << month << " " << day << endl;

    return 0;
}
