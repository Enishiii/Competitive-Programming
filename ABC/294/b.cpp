#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    for (int i = 0; i < h; ++i) {
        string s(w, '.');
        for (int j = 0; j < w; ++j) {
            int x;
            cin >> x;
            if (x != 0) s[j] = 'A' + x - 1;
        }
        cout << s << '\n';
    }

    return 0;
}