/*
問題文
AtCoder では、レーティング上位10 人のハンドルネームには金色の冠が、上位1 人のハンドルネームには白金色の冠が表示されます。
このコンテストが開始した時点で、アルゴリズム部門での上位10 人に入っているプレイヤーのハンドルネームとレーティングは以下のようになっています。

tourist 3858
ksun48 3679
Benq 3658
Um_nik 3648
apiad 3638
Stonefeang 3630
ecnerwala 3613
mnbvmar 3555
newbiedmy 3516
semiexp 3481tourist 3858
ksun48 3679
Benq 3658
Um_nik 3648
apiad 3638
Stonefeang 3630
ecnerwala 3613
mnbvmar 3555
newbiedmy 3516
semiexp 3481

上記のプレイヤーのハンドルネームS が与えられるので、その人のレーティングを出力してください。

制約
S はアルゴリズム部門でレーティング上位10 人に入っているプレイヤーのハンドルネームのいずれかと等しい。
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> rating = {
        {"tourist", 3858},
        {"ksun48", 3679},
        {"Benq", 3658},
        {"Um_nik", 3648},
        {"apiad", 3638},
        {"Stonefeang", 3630},
        {"ecnerwala", 3613},
        {"mnbvmar", 3555},
        {"newbiedmy", 3516},
        {"semiexp", 3481}
    };

    string s;
    cin >> s;

    cout << rating[s] << endl;

    return 0;
}
