#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    // 全探索して問題文の条件を満たせば、文字列置き換えを実行。1周だと漏れがあるかもなので、操作を一回もせずに済むまで繰り返す
    while(1) {
        bool changed = false;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w-1; ++j) {
                if (s[i][j] == 'T' && s[i][j+1] == 'T') {
                    s[i][j] = 'P';
                    s[i][j+1] = 'C';
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    // 答えを出力
    for (int i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }

    return 0;
}
