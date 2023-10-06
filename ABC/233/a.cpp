/*
問題文
サンタさんに手紙を出したい高橋くんは、X 円切手が1 枚だけ貼られた封筒を用意しました。
サンタさんに手紙を届けるためには、貼られている切手の総額がY 円以上である必要があります。
高橋くんは、この封筒に10 円切手を何枚か貼り足すことで、貼られている切手の総額をY 円以上にしたいです。
高橋くんはこの封筒に、最小で何枚の10 円切手を貼り足す必要がありますか?

制約
X,Y は整数
1≤X,Y≤1000
*/

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int diff = y - x;
    if (diff < 0) cout << 0 << endl;
    else if (diff % 10 == 0) cout << diff / 10 << endl;
    else cout << diff / 10 + 1 << endl;

    return 0;
}
