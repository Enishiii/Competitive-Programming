#include <iostream>
#include <vector>
using namespace std;

string readInputString()
{
    string inputString;
    cin >> inputString;
    return inputString;
}

vector<int> findMatchingIndices(const string &pattern, const string &source)
{
    vector<int> matchingIndices;
    int patternIndex = 0;
    for (int i = 0; i < source.size(); ++i)
    {
        if (source[i] == pattern[patternIndex])
        {
            matchingIndices.push_back(i + 1);
            patternIndex++;
        }
    }
    return matchingIndices;
}

void printMatchingIndices(const vector<int> &matchingIndices)
{
    for (int index : matchingIndices)
    {
        cout << index << " ";
    }
    cout << endl;
}

int main()
{
    string pattern = readInputString();
    string source = readInputString();

    vector<int> matchingIndices = findMatchingIndices(pattern, source);

    printMatchingIndices(matchingIndices);

    return 0;
}
