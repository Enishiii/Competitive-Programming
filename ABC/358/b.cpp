#include <iostream>
#include <vector>
using namespace std;


int main() {
    int numCustomers, processingTime;
    cin >> numCustomers >> processingTime;

    vector<int> arrivalTimes(numCustomers);
    for (int i = 0; i < numCustomers; ++i) cin >> arrivalTimes[i];

    int currentTime = 0;
    for (int i = 0; i < numCustomers; ++i) {
        currentTime = max(currentTime, arrivalTimes[i]) + processingTime;
        cout << currentTime << endl;
    }

    return 0;
}
