#include <iostream>
using namespace std;

int calculateTotalCost(int itemCount) {
    int totalCost = 0;
    for (int i = 0; i < itemCount; ++i) {
        int price, quantity;
        cin >> price >> quantity;

        totalCost += price * quantity;
    }
    return totalCost;
}

int main() {
    int itemCount, threshold, shippingCost;
    cin >> itemCount >> threshold >> shippingCost;

    int totalCost = calculateTotalCost(itemCount);

    if (totalCost < threshold) totalCost += shippingCost;

    cout << totalCost << endl;

    return 0;
}
