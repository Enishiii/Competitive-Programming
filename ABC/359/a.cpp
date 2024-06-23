#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "Takahashi") count++;
    }

    cout << count << endl;

    return 0;
}
