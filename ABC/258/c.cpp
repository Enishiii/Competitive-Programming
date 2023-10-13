// 問題文
// 正整数 N, Q と、長さ N の英小文字からなる文字列 S が与えられます。 以下で説明されるクエリを Q 個処理してください。クエリは次の 2 種類のいずれかです。
//      ・1 x : 「S の末尾の文字を削除し、先頭に挿入する」という操作を x 回連続で行う。
//      ・2 x : S のx 番目の文字を出力する。

// 制約
// 2≤N≤5×10^5
// 1≤Q≤5×10^5
// 1≤x≤N
// ∣S∣ = N S は英小文字からなる。
// 2 x の形式のクエリが1 個以上与えられる。
// N, Q, x はすべて整数。

#include <iostream>
#include <stdexcept>
using namespace std;

struct QueryData {
    int index;
    string s;
};

// 入力されたクエリに応じて文字列を操作する関数
void processQuery(int queryType, int x, QueryData& data) {
    if (queryType == 1) {
        data.index = (data.index + data.s.length() - x) % data.s.length();
    } else if (queryType == 2) {
        cout << data.s[(data.index + x -1) % data.s.length()] << endl;
    } else {
        // エラーハンドリング: 不正なクエリタイプに対処
        throw invalid_argument("Invalid query type");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;

    QueryData data = {0, s};

    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;

        // クエリを処理する関数を呼び出す
        try {
            processQuery(type, x, data);
        } catch (const invalid_argument& e) {
            // エラーメッセージをログ出力
            cerr << "Error: " << e.what() << endl;
            return 1; // エラーコードとして1を返す
        }
    }

    return 0;
}
