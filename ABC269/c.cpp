#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> ans;
    for (long long s = n;; s = (s - 1) & n)
    {
        ans.push_back(s);
        if (s == 0)
            break;
    }
    reverse(ans.begin(), ans.end());
    for (long long s : ans)
        cout << s << '\n';

    return 0;
}
