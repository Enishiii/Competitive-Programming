#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int l = 0, r = n-1;
    while(l < r && s[l] == 'a' && s[r] == 'a') {
        l++, r--;
    } 
    while(l < r && s[r] == 'a') r--;
    while(l < r && s[l] == s[r]) {
        l++, r--;
    }
    if (l >= r) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
