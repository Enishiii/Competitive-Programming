#include <iostream>
using namespace std;

class StringPatternChecker {
public:
    StringPatternChecker(const string& source, const string& target) : source_(source), target_(target) {}

    bool matchesPattern() {
        for (int windowSize = 1; windowSize < source_.size(); ++windowSize) {
            for (int startIndex = 0; startIndex < windowSize; ++startIndex) {
                string constructed = constructPattern(windowSize, startIndex);

                if (constructed == target_) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    string source_;
    string target_;

    string constructPattern(int windowSize, int startIndex) {
        string result;
        for (int i = startIndex; i < source_.size(); i += windowSize) {
            result += source_[i];
        }
        return result;
    }
};

int main() {
    string source, target;
    cin >> source >> target;

    StringPatternChecker checker(source, target);
    if (checker.matchesPattern()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
