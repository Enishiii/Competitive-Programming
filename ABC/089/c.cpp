/* 問題文
N 人の人がいて、i 番目の人の名前はSi です。
この中から、以下の条件を満たすように3 人を選びたいです。
    ・全ての人の名前が M,A,R,C,H のどれかから始まっている
    ・同じ文字から始まる名前を持つ人が複数いない
これらの条件を満たすように3 人を選ぶ方法が何通りあるか、求めてください。ただし、選ぶ順番は考えません。
答えが32 bit整数型に収まらない場合に注意してください。

制約
1≤N≤10^5
Si は英大文字からなる
1≤∣Si∣≤10
Si!=Sj (i!=j) */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 各頭文字の人数をカウントするための配列を初期化
    vector<long long> count(5, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        // それぞれの頭文字の人数をカウント
        if (s[0] == 'M') count[0]++;
        else if (s[0] == 'A') count[1]++;
        else if (s[0] == 'R') count[2]++;
        else if (s[0] == 'C') count[3]++;
        else if (s[0] == 'H') count[4]++;
    }

    // ありうる組み合わせを表現する配列を用意(5C3=10通り)
    // 0=M, 1=A, 2=R, 3=C, 4=Hに対応
    vector<int> P = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    vector<int> Q = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
    vector<int> R = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

    long long res = 0;

    // 全ての可能な組み合わせについて、その組み合わせの人数を乗算し、合計を求める
    for (int i = 0; i < 10; ++i) {
        res += count[P[i]] * count[Q[i]] * count[R[i]];
    }

    cout << res << endl;

    return 0;
}
