#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int l = k - i - j;
            if (1 <= l && l <= n)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
