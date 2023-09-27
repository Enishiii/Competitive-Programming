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

vector<int> readColors(int length) {
    vector<int> colors(length);
    for (int& color : colors) cin >> color;
    return colors;
}

vector<vector<int>> getPositions(const vector<int>& colors, int numOfColors) {
    vector<vector<int>> positions(numOfColors+1);
    for (int i = 0; i < colors.size(); ++i)
        positions[colors[i]].push_back(i);
    return positions;
}

string shiftCharacters(const string& str, const vector<vector<int>>& positions) {
    string shifted(str);
    for (const auto& position : positions) {
        int size = position.size();
        for (int i = 0; i < size; ++i) {
            shifted[position[(i+1) % size]] = str[position[i]];
        }
    }
    return shifted;
}

int main() {
    int length, numOfColors;
    string str;
    cin >> length >> numOfColors >> str;

    vector<int> colors = readColors(length);
    vector<vector<int>> positions = getPositions(colors, numOfColors);

    string shiftedString = shiftCharacters(str, positions);

    cout << shiftedString << endl;

    return 0;
}
