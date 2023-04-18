// queue の実装

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<string> names;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            string s;
            cin >> s;
            names.push(s);
        } else if (type == 2) {
            cout << names.front() << endl;
        } else if (type == 3) {
            names.pop();
        }
    }

    return 0;
}
