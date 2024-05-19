#include <iostream>
using namespace std;

int main() {
    long long h;
    cin >> h;

    int ans = 0;
    long long now = 0;
    while(now <= h) {
        now += 1LL << ans;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}
