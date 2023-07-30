/* 問題文
りんご市場に N 人の売り手と M 人の買い手がいます。
i 番目の売り手は、Ai 円以上でならりんごを売ってもよいと考えています。
i 番目の買い手は、Bi 円以下でならりんごを買ってもよいと考えています。
次の条件を満たすような最小の整数 X を求めてください。
条件：りんごを X 円で売ってもよいと考える売り手の人数が、りんごを X 円で買ってもよいと考える買い手の人数以上である。

制約
1≤N,M≤2×10^5
1≤Ai,Bi≤10^9
入力は全て整数である */

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MAX_POSSIBLE_PRICE = 2e9;

bool isPriceAcceptable(ll mid, vector<ll>& seller_prices, vector<ll>& buyer_prices) {
    ll num_sellers_acceptable = 0, num_buyers_acceptable = 0;

    for (ll price : seller_prices) {
        if (mid >= price) num_sellers_acceptable++;
    }

    for (ll price : buyer_prices) {
        if (mid <= price) num_buyers_acceptable++;
    }

    return num_sellers_acceptable >= num_buyers_acceptable;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> seller_prices(n), buyer_prices(m);
    for (int i = 0; i < n; ++i) cin >> seller_prices[i];
    for (int i = 0; i < m; ++i) cin >> buyer_prices[i];

    ll left = 0, right = MAX_POSSIBLE_PRICE;
    ll optimum_price = 0;

    // 二分探索で条件を満たす最小の値段を探す
    while(right - left >= 0) {
        ll mid = (left + right) / 2;

        if (isPriceAcceptable(mid, seller_prices, buyer_prices)) {
            optimum_price = mid;
            right = mid - 1; // より小さい値段で条件を満たすかみていく必要がある
        } else {
            left = mid + 1;
        }
    }

    cout << optimum_price << endl;

    return 0;
}
