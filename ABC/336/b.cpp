#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string convertBinaryFrom(int number) {
    bitset<50> bs(number);

    string binary = bs.to_string();
    return binary;
}

int ctz(string binary) {
    int countZero = 0;
    for (int i = binary.size()-1; i >= 0; --i) {
        if (binary[i] == '1') break;

        countZero++;
    }
    return countZero;
}

int main() {
    int number;
    cin >> number;

    string binary = convertBinaryFrom(number);

    int result = ctz(binary);
    cout << result << endl;

    return 0;
}
