#include <iostream>
using namespace std;

int main() {
    int itemCount, threshold, shippingCost;
    cin >> itemCount >> threshold >> shippingCost;

    int totalCost = 0;
    for (int i = 0; i < itemCount; ++i) {
        int price, quantity;
        cin >> price >> quantity;

        totalCost += price * quantity;
    }

    if (totalCost < threshold) totalCost += shippingCost;

    cout << totalCost << endl;

    return 0;
}
