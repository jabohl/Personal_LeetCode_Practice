#include <vector>
#include <algorithm>
#include <set>


class SmallestInfiniteSet {
private:
    int nextSmallestInSet;
    std::set<int> ReaddedValueSet;

public:
    SmallestInfiniteSet() {
        nextSmallest = 1;
    }
    

    int popSmallest() {
        if (!ReaddedValueSet.empty()) {
            int smallestInSet = *ReaddedValueSet.begin();


            ReaddedValueSet.erase(ReaddedValueSet.begin());


            return smallestInSet;
        }


        return nextSmallest++;
    }
    

    void addBack(int ViableValue) {
        if (ViableValue < nextSmallest) {
            ReaddedValueSet.insert(ViableValue);
        }
    }
};
