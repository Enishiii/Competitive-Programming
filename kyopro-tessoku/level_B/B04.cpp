#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0, i = 1;
    while (n)
    {
        int b = n % 10;
        if (b)
        {
            ans += i;
        }
        n /= 10;
        i *= 2;
    }
    cout << ans << endl;

    return 0;
}
