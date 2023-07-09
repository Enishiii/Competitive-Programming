#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Event {
    ll day;
    ll change;
};

bool comp(const Event &a, const Event &b) {
    if (a.day == b.day)
        return a.change > b.change;
    else
        return a.day < b.day;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<Event> events;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        events.push_back({1, b});
        events.push_back({a + 1, -b});
    }

    sort(events.begin(), events.end(), comp);

    ll total = 0;
    for (ll i = 0; i < 2 * N; i++) {
        total += events[i].change;
        if (i < 2 * N - 1 && events[i].day != events[i + 1].day && total <= K) {
            cout << events[i].day << endl;
            return 0;
        }
    }

    cout << events[2 * N - 1].day << endl;

    return 0;
}
