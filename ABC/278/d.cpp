#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int read_int() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int n = read_int();

    vector<ll> a(n);
    for (auto &num : a) cin >> num;

    ll base_num = 0;
    map<int, ll> modification_map;
    for (int i = 0; i < n; ++i) {
        modification_map[i] = a[i];
    }

    int q = read_int();

    for (int i = 0; i < q; ++i) {
        int query_type = read_int();

        switch(query_type) {
            case 1: {
                int x = read_int();
                base_num = x;
                modification_map.clear();
                break;
            }
            case 2: {
                int index = read_int() - 1;
                int x = read_int();
                modification_map[index] += x;
                break;
            }
            case 3: {
                int index = read_int() - 1;
                cout << base_num + modification_map[index] << endl;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
