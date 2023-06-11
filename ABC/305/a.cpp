/* 問題文
全長100km のマラソンコースがあります。 マラソンコースにはスタートから
5km おきに給水所が設置されており、スタート地点・ゴール地点とあわせて
21 箇所の給水所があります。
高橋くんは、このマラソンコースのNkm 地点にいます。 高橋くんに最も近い給水所は何km 地点の給水所か求めてください。
この問題の制約のもとで、最も近い給水所が1 つに定まることが証明できます。

制約
0≤N≤100
N は整数*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 10 == 0 || n % 10 == 5) cout << n << endl;
    else if (n % 10 == 1 || n % 10 == 6) cout << n-1 << endl;
    else if (n % 10 == 2 || n % 10 == 7) cout << n-2 << endl;
    else if (n % 10 == 3 || n % 10 == 8) cout << n+2 << endl;
    else if (n % 10 == 4 || n % 10 == 9) cout << n+1 << endl;

    return 0;
}
