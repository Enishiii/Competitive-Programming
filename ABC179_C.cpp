#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int b = 1;
    while((n-1)/b > 0) {
        ans += (n-1) / b;
        b++;
    }
    cout << ans << endl;
    
    return 0;
}
