#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

/**
 * Provides shuffle and reset functionality for an array.
 * Allows shuffling the array and resetting it to the original order.
 * 
 * Time Complexity: O(n) for shuffle, O(n) for reset
 * Space Complexity: O(n) to store the original array
 */
class Solution {
private:
    std::vector<int> originalArray;
    std::vector<int> currentArray;
    std::mt19937 generator;

public:
    Solution(std::vector<int> nums) {
        // Store a copy of the original array for reset functionality
        originalArray = nums;
        currentArray = nums;
        // Initialize random number generator with seed
        generator.seed(std::time(nullptr));
    }
    
    /** Resets the array to its original order. */
    std::vector<int> reset() {
        // Restore the current array to the original state
        currentArray = originalArray;
        return currentArray;
    }
    
    /** Returns a random shuffled version of the array. */
    std::vector<int> shuffle() {
        // Create a copy of the current array to shuffle
        std::vector<int> shuffledArray = currentArray;
        
        // Shuffle the copy using Fisher-Yates algorithm
        std::shuffle(shuffledArray.begin(), shuffledArray.end(), generator);
        
        return shuffledArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
