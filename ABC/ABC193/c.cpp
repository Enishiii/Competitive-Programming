#include <iostream>
#include <set>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    set<long long> s;
    for (long long a = 2; a * a <= n; ++a)
    {
        long long x = a * a;
        while (x <= n)
        {
            s.insert(x);
            x *= a;
        }
    }
    cout << n - s.size() << endl;

    return 0;
}
