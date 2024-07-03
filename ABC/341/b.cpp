#include <iostream>
#include <vector>
using namespace std;

void transferCurrencyBetweenCountries(vector<long long>& currencies) {
    int numCountries = currencies.size();
    for (int i = 0; i < numCountries - 1; ++i) {
        int cost, gain;
        cin >> cost >> gain;

        currencies[i + 1] += (currencies[i] / cost) * gain;
    }

}

int main() {
    int numCountries;
    cin >> numCountries;

    vector<long long> currencies(numCountries);
    for (auto& currency : currencies) cin >> currency;

    transferCurrencyBetweenCountries(currencies);

    cout << currencies[numCountries-1] << endl;

    return 0;
}
