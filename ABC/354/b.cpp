#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numUsers;
    cin >> numUsers;

    vector<string> usernames(numUsers);
    vector<int> ratings(numUsers);
    int totalRatings = 0;

    for (int i = 0; i < numUsers; ++i) {
        cin >> usernames[i] >> ratings[i];
        totalRatings += ratings[i];
    }

    sort(usernames.begin(), usernames.end());
    cout << usernames[totalRatings % numUsers] << endl;

    return 0;
}
