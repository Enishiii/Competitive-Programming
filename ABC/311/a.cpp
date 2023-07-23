/* 問題文
A, B, C からなる文字列S が与えられます。
S は A, B, C を全て含むことが保証されます。
S を左から1 文字ずつ見ていったときに、はじめて次の条件を満たした状態になるのは、左から何文字目まで見たときですか？
    ・A, B, C が全て1 回以上出現している。

制約
3≤N≤100
S は A, B, C からなる長さN の文字列
S は A, B, C を全て含む */

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    set<char> st; // 文字の種類数を管理
    for (int i = 0; i < n; ++i) {
        st.insert(s[i]);

        if (st.size() == 3) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
