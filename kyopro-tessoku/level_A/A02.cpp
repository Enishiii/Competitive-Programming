#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == x)
        {
            found = true;
        }
    }
    if (found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
