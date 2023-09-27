/*
問題文
英小文字からなる長さN の文字列S が与えられます。S の各文字は色1 、色
2 、… 、色M のM 色のうちのいずれかで塗られており、i=1,2,…,N について、S のi 文字目は色Ci で塗られています。
各i=1,2,…,M について、この順番に下記の操作を行います。
    ・S の色i で塗られた文字からなる部分を、右に1 つ巡回シフトする。 すなわち、S の 色i で塗られた文字の位置が先頭のものから順にp1,p2,p3,…,pk 文字目であるとき、S のp1,p2,p3,…,pk 文字目を、それぞれ、S のpk,p1,p2,…,pk−1 文字目で同時に置き換える。
上記の操作をすべて行った後の、最終的なS を出力してください。
なお、M 色あるどの色についても、その色で塗られたS の文字が必ず1 つ以上存在することが、制約として保証されます。

制約
1≤M≤N≤2×10^5
1≤Ci≤M
N,M,Ci はすべて整数
S は英小文字からなる長さN の文字列
任意の整数1≤i≤M に対して、ある整数1≤j≤N が存在してCj=i が成り立つ
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> c(n);
    vector<vector<int>> p(m+1, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        p[c[i]].push_back(i);
    }

    string t(s); // sをコピーして、初期化
    for (int i = 1; i <= m; ++i) {
        int sz = p[i].size();
        for (int j = 0; j < sz; ++j) {
            t[p[i][(j+1)%sz]] = s[p[i][j]];
        }
    }

    cout << t << endl;

    return 0;
}
