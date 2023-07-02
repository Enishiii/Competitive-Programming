#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int s[8];
    bool ok = true;
    for (int i = 0; i < 8; ++i)
    {
        cin >> s[i];
        if (s[i] < 100 || s[i] > 675)
            ok = false;
        if (s[i] % 25 != 0)
            ok = false;
        if (i > 0)
        {
            if (s[i] < s[i - 1])
                ok = false;
        }
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
