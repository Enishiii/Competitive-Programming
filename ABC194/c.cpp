#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    const int MaxA = 200;
    vector<int> d(MaxA * 2 + 1);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = -MaxA; j <= MaxA; ++j)
        {
            int c = d[MaxA + j];
            int x = a[i] - j;
            ans += (long long)x * x * c;
        }
        d[MaxA + a[i]]++;
    }
    cout << ans << endl;

    return 0;
}
