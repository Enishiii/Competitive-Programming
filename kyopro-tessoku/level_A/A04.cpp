#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int x = 9; x >= 0; --x)
    {
        int divisor = (1 << x);
        cout << (n / divisor) % 2;
    }
    cout << endl;

    return 0;
}
