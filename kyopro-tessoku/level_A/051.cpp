#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<string> books;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            string s;
            cin >> s;
            books.push(s);
        } else if (t == 2) {
            cout << books.top() << endl;
        } else if (t == 3) {
            books.pop();
        }
    }

    return 0;
}
