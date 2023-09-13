/*
問題文
高橋くんは、N 個の単語からなる文章をウィンドウに表示させようとしています。 すべての単語の縦幅は等しく、i 番目(1≤i≤N) の単語の横幅はLi です。
文章は、横幅1 の空白を単語の区切りとしてウィンドウに表示されます。 より厳密には、高橋くんが横幅W のウィンドウに文章を表示しているとき、次の条件が成り立っています。
    ・文章はいくつかの行に分かれている。
    ・1 番目の単語は一番上の行の先頭に表示されている。
    ・i 番目(2≤i≤N) の単語は、i−1 番目の単語の次に間隔を1 だけ開けて表示されているか、i−1 番目の単語が含まれる行の下の行の先頭に表示されているかの一方である。それ以外の場所に表示されていることはない。
    ・それぞれの行の横幅はW を超えない。ここで、行の横幅とは最も左にある単語の左端から最も右にある単語の右端までの距離を指す。
高橋くんが文章をウィンドウに表示したとき、文章がM 行に収まりました。 ウィンドウの横幅としてありえる最小の値を求めてください。

制約
1 ≤ M ≤ N ≤ 2×10^5
1 ≤ Li ≤ 10^9 (1≤i≤N)
入力はすべて整数
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidWidth(long long width, const vector<int> &words, int M) {
    int lines = 1;
    long long currentWidth = 0;

    for (int i = 0; i < words.size(); ++i) {
        // 改行すべきか判定
        if (currentWidth + words[i] + (currentWidth == 0 ? 0 : 1) > width) {
            lines++;
            currentWidth = 0;
        }
        currentWidth += words[i] + (currentWidth == 0 ? 0 : 1);
    }
    
    return lines <= M;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> words(N);
    long long sumWidths = 0;
    int maxWidth = 0;

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        sumWidths += words[i];
        maxWidth = max(maxWidth, words[i]);
    }

    // 二分探索で最小の横幅を見つける
    long long left = maxWidth, right = sumWidths + N - 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (isValidWidth(mid, words, M)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}
