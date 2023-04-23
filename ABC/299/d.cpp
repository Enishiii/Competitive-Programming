#include <iostream>

int main() {
    using namespace std;
    int n;
    cin >> n;

    // 二分探索で1~Nまでの範囲を探索する。問題の条件を満たせばループを抜ける
    int l = 1, r = n;
    char s;
    while(r - l > 1) {
        int i = (l+r) / 2;
        cout << "? " << i << endl;

        cin >> s;
        if (s == '0') l = i;
        else if (s == '1') r = i;
    }
    // lが答え
    cout << "! " << l << endl;

    return 0;
}
