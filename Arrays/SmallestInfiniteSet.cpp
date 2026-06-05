#include <vector>
#include <algorithm>
#include <set>

/**
 * Manages an infinite set of positive integers starting from 1.
 * Supports removing the smallest element and adding numbers back.
 * 
 * Time Complexity: 
 *     - popSmallest: O(1) amortized
 *     - addBack: O(log n)
 * Space Complexity: O(n) for storing removed numbers
 */
class SmallestInfiniteSet {
private:
    int nextSmallest;
    std::set<int> addedBack;

public:
    SmallestInfiniteSet() {
        // Start with the smallest positive integer
        nextSmallest = 1;
    }
    
    /**
     * Removes and returns the smallest number from the set.
     * @return The smallest integer in the set
     */
    int popSmallest() {
        // Check if there are numbers that were added back and are smaller
        if (!addedBack.empty()) {
            int smallest = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return smallest;
        }
        
        // Otherwise, return the next smallest from the infinite sequence
        return nextSmallest++;
    }
    
    /**
     * Adds a number back to the set if it's not already present.
     * @param num The number to add back to the set
     */
    void addBack(int num) {
        // Only add if it's less than the next smallest that hasn't been popped
        if (num < nextSmallest) {
            addedBack.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
