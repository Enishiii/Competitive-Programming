#include <iostream>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    int present = 0;
    if (n == 100) n++;
    
    if (d == 0) {
        present = n;
    } else if (d == 1) {
        present = 100*n;
    } else if (d == 2) {
        present = 10000*n;
    }
    cout << present << endl;

    return 0;
}