#include <iostream>
using namespace std;

class LiquidManager {
public:
    LiquidManager(int maxGlass, int maxMug): maxGlass_(maxGlass), maxMug_(maxMug), currentGlass_(0), currentMug_(0) {}

    void transferLiquid(int transferCount) {
        for (int i = 0; i < transferCount; ++i) {
            if (currentGlass_ == maxGlass_) currentGlass_ = 0;
            else if (currentMug_ == 0) currentMug_ = maxMug_;
            else {
                int transferable = min(maxGlass_ - currentGlass_, currentMug_);
                currentGlass_ += transferable;
                currentMug_ -= transferable;
            }
        }
    }

    void printFinalLiquidStatus() {
        cout << currentGlass_ << " " << currentMug_ << endl;
    }

private:
    int maxGlass_;
    int maxMug_;
    int currentGlass_;
    int currentMug_;
};

int main() {
    int transferCount, maxGlass, maxMug;
    cin >> transferCount >> maxGlass >> maxMug;

    LiquidManager lm(maxGlass, maxMug);
    lm.transferLiquid(transferCount);
    lm.printFinalLiquidStatus();

    return 0;
}
