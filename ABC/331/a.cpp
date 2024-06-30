#include <iostream>
using namespace std;

struct CalenderSystem {
    int months;
    int days;
};

struct Date {
    int year;
    int month;
    int day;
};

void addOneDay(const CalenderSystem& calender, Date& date) {
    date.day++;

    if (date.day > calender.days) {
        date.month++;
        date.day = 1;
    }

    if (date.month > calender.months) {
        date.year++;
        date.month = 1;
    }
}

int main() {
    CalenderSystem calender;
    cin >> calender.months >> calender.days;

    Date date;
    cin >> date.year >> date.month >> date.day;

    addOneDay(calender, date);

    cout << date.year << " " << date.month << " " << date.day << endl;

    return 0;
}
