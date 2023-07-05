/* 問題文
A さん、B さん、C さんの3 人が以下のようなカードゲームをプレイしています。
    ・最初、3 人はそれぞれ a、b、c いずれかの文字が書かれたカードを、何枚か持っている。これらは入力で与えられた順番に持っており、途中で並べ替えたりしない。
    ・A さんのターンから始まる。
    ・現在自分のターンである人がカードを1 枚以上持っているならば、そのうち先頭のカードを捨てる。その後、捨てられたカードに書かれているアルファベットと同じ名前の人 (例えば、カードに a と書かれていたならば A さん) のターンとなる。
    ・現在自分のターンである人がカードを1 枚も持っていないならば、その人がゲームの勝者となり、ゲームは終了する。
3 人が最初に持っているカードがそれぞれ先頭から順に与えられます。 具体的には、文字列SA、SB、SC が与えられます。文字列SA のi 文字目 (1≤i≤∣S
A∣) に書かれている文字が、A さんの持っている中で先頭からi 番目のカードに 書かれている文字です。文字列SB、SC についても同様です。
最終的に誰がこのゲームの勝者となるかを求めてください。

制約
1≤∣SA∣≤100
1≤∣SB∣≤100
1≤∣SC∣≤100
SA、SB、SC に含まれる文字はそれぞれ a、b、c のいずれか */

#include <iostream>
#include <vector>
using namespace std;

// 制約が小さいので、素直にシミュレーションして解く

// 文字列のインデックスを更新し、次に処理する文字列を決定する関数
int updateIndex(int& index, const string& str, const char player) {
    // 文字列の終端に達した場合、プレーヤー名を出力し終了
    if (index == str.size()) {
        cout << player << endl;
        return -1;
    }

    // 次に処理する文字を取得し、インデックスを進める
    char next_char = str[index];
    index++;

    // 次に処理する文字に応じて、次のインデックスを決定
    if (next_char == 'a') return 1;
    else if (next_char == 'b') return 2;
    else if (next_char == 'c') return 3;

    return 0;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    // 各プレーヤーの文字列を１つの配列にまとめる
    vector<string> str_list = {a, b, c};

    // 各プレーヤーのインデックスを１つの配列にまとめる
    int idx_a = 0, idx_b = 0, idx_c = 0;
    vector<int> index_list = {idx_a, idx_b, idx_c};

    // プレーヤー名を１つの配列にまとめる
    char players[] = {'A', 'B', 'C'};

    int next = 1; // 誰のターンかを管理（1:a, 2:b, 3:cのターン）

    while(1) {
        // インデックスを更新し、次に処理する文字列を決定する
        next = updateIndex(index_list[next-1], str_list[next-1], players[next-1]);

        if (next == -1) return 0;
    }

    return 0;
}
