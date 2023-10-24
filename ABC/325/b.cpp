// 問題文
// キーエンスには世界各地に N 個の拠点があり、1 から N までの番号が付けられています。 拠点 i には Wi 人の社員が所属しており、世界標準時で 0 時のとき拠点 i はXi 時です。
// あなたはキーエンス全社で 1 時間の会議を開きたいです。 各社員は、会議の開催時間帯が所属する拠点における 9:00-18:00 の時間帯に完全に含まれる場合にのみ会議に参加できます。 なるべく多くの社員が参加できるように会議の開催時間帯を決めるとき、会議に参加できる社員の数の最大値を求めてください。

// 制約
// 1≤N≤1000
// 1≤Wi≤10^6
// 0≤Xi <24
// 入力は全て整数

#include <iostream>
#include <vector>
using namespace std;

const int HOURS_IN_A_DAY = 24;
const int WORK_HOURS = 9;

int calculateAttendeesForHour(const vector<int>& employeesPerHour, int startHour) {
    int totalAttendees = 0;
    for (int j = 0; j < WORK_HOURS; ++j) {
        totalAttendees += employeesPerHour[(startHour + j) % HOURS_IN_A_DAY];
    }
    return totalAttendees;
}

int main() {
    int n;
    cin >> n;

    vector<int> employeesPerHour(HOURS_IN_A_DAY, 0);
    for (int i = 0; i < n; ++i) {
        int w, x;
        cin >> w >> x;
        employeesPerHour[x] += w;
    }

    int maxAttendees = 0;
    for (int startHour = 0; startHour < HOURS_IN_A_DAY; startHour++) {
        maxAttendees = max(maxAttendees, calculateAttendeesForHour(employeesPerHour, startHour));
    }

    cout << maxAttendees << endl;

    return 0;
}
