#include <vector>
#include <algorithm>
#include <set>


class SmallestInfiniteSet {
private:
    int nextSmallest;
    std::set<int> addedBack;

public:
    SmallestInfiniteSet() {
        nextSmallest = 1;
    }
    

    int popSmallest() {
        if (!addedBack.empty()) {
            int smallest = *addedBack.begin();


            addedBack.erase(addedBack.begin());


            return smallest;
        }


        return nextSmallest++;
    }
    

    void addBack(int num) {
        if (num < nextSmallest) {
            addedBack.insert(num);
        }
    }
};
